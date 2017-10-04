import sys
try:
    import matplotlib.pyplot as pyp
except (ImportError):
    print "No module installed here, you cannot continue !"
    sys.exit()
import numpy as np

def display(arr1, arr2, t1, t2, prob):
    print("loi binomial:")
    print("\ttemps de calcul:\t\t {} ms".format(round(t1 * 1000, 2)))
    print("\tprobabilite d'encombremennt:\t {} % ".format(round(prob * 100, 1)))

    print("loi de Poisson:")
    print("\ttemps de calcul:\t\t {} ms".format(round(t2 * 1000, 2)))
    print("\tprobabilite d'encombremennt:\t {} %".format(round(prob * 100, 1)))

    pyp.axis([0, 50, 0, 0.12])
    pyp.bar(range(len(arr1)), arr1, width=-0.4, label="Loi binomiale", color="blue")
    pyp.bar(range(len(arr2)), arr2, width=0.4, label="Loi de Poisson", color="red")
    pyp.legend(loc="upper right")
    pyp.xlabel("nb d'appels simultanes")
    pyp.ylabel("probabilite")
    pyp.title("203hotline")
    pyp.show()
