class Bidon():
    zaz = 'je suis un pro du python'
    def __init__(self, txt, num=42, **kwargs):
        self.txt = txt
        self.num = num
        for k, v in kwargs.items():
            setattr(self, k, v)

def var2listsort(*argv):
    list = []
    for arg in argv:
        list.append(arg)
    list.sort()
    return list