from jdr import *

p1 = D6() + d6 + 1
print(repr(p1))

print("__")

p2 = d6 * 4 + 12 + d8 * 8

print(repr(p2))

AbstractResult.seed(4224)
print(p1.throw())
print(p2.throw())
print(p1.show())
print(p2.show())

if type(p1.roll()).__name__ != 'generator':
    raise TypeError('la methode roll doit retou')

for t in (D6() + D4()).roll():
    print(t)