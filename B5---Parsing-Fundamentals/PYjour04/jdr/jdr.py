import random

###

class AddExpr:
    def __init__(self, lhs, rhs):
        self.lhs = lhs
        self.rhs = rhs
        self.result = 0

    def __repr__(self) -> str:
        return repr(self.lhs) + ' + ' + repr(self.rhs)

    def throw(self) -> int:
        if self.result == 0:
            a = self.lhs.throw()
            b = self.rhs.throw()
            self.result = a + b
        return self.result

class MulExpr:
    def __init__(self, lhs, rhs):
        self.lhs = lhs
        self.rhs = rhs
        self.result = 0

    def __repr__(self) -> str:
        return repr(self.rhs) + repr(self.lhs)

    def throw(self) -> int:
        if self.result == 0:
            a = self.lhs.throw()
            b = self.rhs.throw()
            self.result = a * b
        return self.result


class Pool:
    def __init__(self, op):
        self.op = op

    def throw(self):
        return self.op.throw()

    def __add__(self, rhs):
        if type(rhs) is int:
            rhs = FrozenDice(rhs)
        return Pool(AddExpr(self, rhs))

    def __mul__(self, rhs):
        if type(rhs) is int:
            rhs = FrozenDice(rhs)
        return Pool(MulExpr(self, rhs))

    def __repr__(self) -> str:
        return repr(self.op)

class AbstractResult(Pool):
    min = 1
    max = 1
    def __init__(self):
        self.result = 0

    def __repr__(self):
        return type(self).__name__

    def throw(self):
        if self.result == 0:
            self.result = random.randint(type(self).min, type(self).max)
        return self.result

    def seed(s):
        random.seed(s)

class FrozenDice(AbstractResult):
    def __init__(self, v):
        self.result = v
        self.min = v
        self.max = v

    def __repr__(self):
        return str(self.result)

    def throw(self):
        return self.result

####

class D4(AbstractResult):
        max=4

class D6(AbstractResult):
    max = 6

class D8(AbstractResult):
    max = 8

class D10(AbstractResult):
    max = 10

class D12(AbstractResult):
    max = 12

class D20(AbstractResult):
    max = 20


d4 = D4()
d6 = D6()
d8 = D8()
d10 = D10()
d12 = D12()
d20 = D20()