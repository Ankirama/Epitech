from urllib.request import urlopen, Request
from urllib.parse import urlencode
from pyrser import meta, fmt
from pyrser.parsing import node
import collections
from pprint import pprint

TABULATION = 4

@meta.add_method(node.Node)
def to_dxml(self, name='.root', tab=0):
    '''
    main function (recursively called) to create a node
    :param name: node name
    :param tab: tabulation in our result
    :return: our xml string created
    '''
    items = collections.OrderedDict(sorted(vars(self).items()))
#    for k,v in items.items():
#        print("key: %s - value: %s - type: %s" % (k, v, type(v)))
    xml = create_node(name, tab, items)
    return xml

def create_node(name, tab, items):
    '''
    create a specific node with tabulation and add every items in this node
    :param name: node name
    :param tab: tabulation in our node
    :param items: each items in our node
    :return: our node created
    '''
    def init_node(name, tab, my_type='object'):
        '''
        It will init our node (like <.root type = object>)
        :param name: node name
        :param tab: tabulation in our node
        :return: node header created
        '''
        node = ' ' * tab
        node += '<%s type = %s>\n' % (name, my_type)
        return node
    def close_node(name, tab):
        '''
        It will close our node (like </.root>)
        :param name: node name to close
        :param tab: tabulation in our node
        :return: node header closed
        '''
        node = ' ' * tab
        if (name[:5] == '.idx '):
            node += '</%s>\n' % '.idx'
        else:
            node += '</%s>\n' % name
        return node
        
    def add_list(name, tab, obj_type, lst):
        '''
        Add a list in our xml string
        :param name: name list or name element like <.idx __value = 3 type = list>
        :param tab: tabulation in our list
        :param obj_type: list (useless param)
        :return:
        '''
        xml_lst = init_node(name, tab, obj_type)
        for i, elt in enumerate(lst):
            xml_lst += add_item('.idx __value = ' + str(i), tab + TABULATION, type(elt).__name__, elt)
        if name[:5] == '.idx ':
            xml_lst += close_node('.idx', tab)
        else:
            xml_lst += close_node(name, tab)
        return xml_lst

    def add_dict(name, tab, obj_type, dico):
        '''

        :param name:
        :param tab:
        :param obj_type:
        :param dict:
        :return:
        '''
        dico = collections.OrderedDict(sorted(dico.items()))
        xml_dict = init_node(name, tab, obj_type)
        for k, v in dico.items():
            xml_dict += add_item(""".idx __key = '%s'""" % k, tab + TABULATION, type(v).__name__, v)
        if name[:5] == '.idx ':
            xml_dict += close_node('.idx', tab)
        else:
            xml_dict += close_node(name, tab)
        return xml_dict

    def add_blob(name, tab, obj_type, myblob):
        '''

        :param name:
        :param tab:
        :param obj_type:
        :param myblob:
        :return:
        '''
        xml_blob = init_node(name, tab, 'blob')
        test = ' ' * (tab + 4)
        for c in myblob:
            tmp = hex(c).replace('0x', '').upper()
            if len(tmp) == 1:
                tmp = '0' + tmp
            test += tmp
            test += ' ' * 1
        test = test[:len(test) - 1]
        xml_blob += "%s\n" % test
        xml_blob += close_node(name, tab)
        return xml_blob

    def add_set(name, tab, obj_type, my_set):
        '''

        :param name:
        :param tab:
        :param obj_type:
        :param my_set:
        :return:
        '''
        items = sorted(my_set)
        xml_set = init_node(name, tab, obj_type)
        for elt in items:
            if isinstance(elt, str):
                xml_set += add_item("""'%s'""" % elt, tab + TABULATION, type(elt).__name__, elt, True)
            else:
                xml_set += add_item("""%s""" % elt, tab + TABULATION, type(elt).__name__, elt, True)
        if name[:5] == '.idx ':
            xml_set += close_node('.idx', tab)
        else:
            xml_set += close_node(name, tab)
        return xml_set

    def add_item(name, tab, obj_type, value, set_type=False):
        '''
        Add an item into our current node
        :param name: name for the current item (like flags for <flags bool = True />
        :param tab: tabulation in our node
        :param obj_type: object type like bool, float etc
        :param value: item value
        :return: item created
        '''
        item = ''
        if set_type or value == None:
            item += ' ' * tab
            item += '<%s/>\n' % name
        elif isinstance(value, node.Node):
            item += value.to_dxml(name, tab)
        elif isinstance(value, bytes):
            item += add_blob(name, tab, obj_type, value)
        elif isinstance(value, str):
            item += ' ' * tab
            item += '''<%s %s = '%s'/>\n''' % (name, obj_type, value)
        elif isinstance(value, list):
            item += add_list(name, tab, obj_type, value)
        elif isinstance(value, dict):
            item += add_dict(name, tab, obj_type, value)
        elif isinstance(value, set):
            item += add_set(name, tab, obj_type, value)
        else:
            item += ' ' * tab
            item += '<%s %s = %s/>\n' % (name, obj_type, value)
        return item

    xml = init_node(name, tab)
    for k,v in items.items():
        '''
        this loop will travel our items and check if we have a new node:
        if yes, then it will recursively call to_dxml on the current node
        else it will add our item to our xml string
        :param k: our key in our dictionnary (like flags for {'flags': True})
        :param v: our value in our dictionnary (like True in {'flags': True})
        '''
        xml += add_item(k, tab + TABULATION, type(v).__name__, v)

    if (name[:5] == '.idx '):
        xml += close_node('.idx', tab)
    else:
        xml += close_node(name, tab)
    return xml
