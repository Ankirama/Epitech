from pyrser             import grammar, meta
from pyrser.directives  import ignore

class parserPseudoIni(grammar.Grammar):
    ''' Pyrser INI parser'''
    entry = 'ini'
    grammar = '''
    ini = [#is_init_all(_) [ section:s #is_create_section(_, s)]+ eof]

    section = [#is_init_section(_) '[' id:name ']' #is_add_section_name(_, name)
                [clefValeur:all #is_add_section_all(_, all)]+]

    clefValeur = [ id:i '=' valeur:v #is_create_clefValeur(_, i, v) ]

    valeur = [ [ id:i #is_id(_, i)
                | num:n #is_num(_, n)
                | string:s #is_string(_, s)]]
    '''

@meta.hook(parserPseudoIni)
def is_init_all(self, ast):
    '''
    it will init our dico (just create sections and init it to {})
    '''
    ast.sections = {}
    return True

@meta.hook(parserPseudoIni)
def is_create_section(self, ast, section):
    '''
    add an element in our dico (like {'test': {}}
    with section.name: 'test' and section.all: {}
    '''
    ast.sections[section.key] = section.all
    return True

@meta.hook(parserPseudoIni)
def is_init_section(self, ast):
    '''
    create an empty section
    '''
    ast.key = None
    ast.all = {}
    return True

@meta.hook(parserPseudoIni)
def is_add_section_name(self, ast, name):
    '''
    set a name for our section (like ['log'])
    '''
    ast.key = self.value(name)
    return True

@meta.hook(parserPseudoIni)
def is_add_section_all(self, ast, all):
    ast.all[all.key] = all.value
    return True

@meta.hook(parserPseudoIni)
def is_create_clefValeur(self, ast, key, value):
    '''
    it will create our property (tata = 42) for example
    '''
    ast.key = self.value(key)
    ast.value = value.value
    return True

@meta.hook(parserPseudoIni)
def is_id(self, ast, myId):
    '''
    it will create an identifier and set it in value
    '''
    ast.value = self.value(myId)
    return True

@meta.hook(parserPseudoIni)
def is_num(self, ast, num):
    ast.value = int(self.value(num))
    return True

@meta.hook(parserPseudoIni)
def is_string(self, ast, string):
    ast.value = self.value(string)
    return True