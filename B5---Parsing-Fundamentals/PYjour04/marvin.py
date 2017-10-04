from urllib.request import urlopen, Request
from urllib.parse import urlencode
from cnorm.parsing.declaration import Declaration
import cnorm.nodes
from cnorm.passes import to_c
from pprint import pprint

types = {
    'int': 'est un entier',
    'float': 'est un floattant',
    'double': 'est un floattant double precision',
}

specifiers = {
    4: 'a la jack',
    5: 'a la super-jack',
    6: 'court',
}

storages = {
    1: 'stocker dans un registre qui est initialise a une certaine valeur mais ca me saoule',
    3: 'definie localement',
}

qualifiers = {
    0: 'constant',
}

def print_primaryType(node):
    string = ""
    if not node.assign_expr():
        string += "je definie!"
    else:
        string += "je declare!"
    if node._name == 'bite':
        return ("je declare! bite est un champs de bit\n")
    else:
        string += " " + node._name
    if node._ctype._identifier in types:
        string += ' ' + types[node._ctype._identifier]
    else:
        string += ' est un ' + node._ctype._identifier
    if hasattr(node._ctype, '_sign') and node._ctype._sign == 2:
        string += " positif ou nul"
    if node._ctype._specifier in specifiers:
        string += " " + specifiers[node._ctype._specifier]
    if isinstance(node._ctype._decltype, cnorm.nodes.QualType) and node._ctype._decltype._qualifier == 1:
        string += " constant"
    if node._ctype._storage in storages:
        string += " " + storages[node._ctype._storage]
    return (string + '\n')

def marvin(ast):
#    cparse = Declaration()
#    ast = cparse.parse_file('test.c')
    str = ''
    for node in ast.body:
        if isinstance(node._ctype, cnorm.nodes.FuncType):
            pass
        elif isinstance(node._ctype, cnorm.nodes.PrimaryType):
            str += print_primaryType(node)
#            print("type: %s \nname: %s \nassign_expr: %s \ncolon_expr: %s" % (node._ctype, node._name, node.assign_expr(), node.colon_expr()))
#            print("specifier: %s" % node._ctype._specifier)
#            print("storage: %s" % node._ctype._storage)
#        print("______________________________________________________________________________________")
    return str
