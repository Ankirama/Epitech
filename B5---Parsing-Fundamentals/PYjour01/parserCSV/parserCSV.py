from pyrser             import grammar, meta
from pyrser.directives  import ignore

class parserCSV(grammar.Grammar):
    '''pyrser CSV parser'''
    entry = 'csv'
    grammar = '''
        csv = [#is_array(_) [ line:l #add_newline(_, l) eol ]* ]

        line = [#is_newline(_) [ cell:c #add_item(_, c) ';' ]+ ]

        cell = [ id ]

    '''

@meta.hook(parserCSV)
def is_array(self, ast):
    ast.lines = []
    return True

@meta.hook(parserCSV)
def add_newline(self, ast, line):
    ast.lines.append(line.line)

@meta.hook(parserCSV)
def is_newline(self, ast):
    ast.line = []
    return True

@meta.hook(parserCSV)
def add_item(self, ast, item):
    ast.line.append(self.value(item))
    return True