#!/usr/bin/python2.7

from math import *
import  sys

def     usage():
    print "Usage ./202invendus a b with a,b >= 50 !"
    sys.exit()

def     esperance_variance(loi_xy, loi_z):
    esp_x = 0
    esp_y = 0
    esp_z = 0
    var_x = 0
    var_y = 0
    var_z = 0

    i = 1
    while (i < 6):
        esp_x = esp_x + i * 10 * loi_xy[6][i]
        var_x = var_x + pow(i * 10, 2) * loi_xy[6][i]
        esp_y = esp_y + i * 10 * loi_xy[i][6]
        var_y = var_y + pow(i * 10, 2) * loi_xy[i][6]
        i = i + 1
    var_x = var_x - pow(esp_x, 2)
    var_y = var_y - pow(esp_y, 2)
    i = 0
    while (i < 9):
        esp_z = esp_z + (i + 2) * 10 * loi_z[i]
        var_z = var_z + pow((i + 2) * 10, 2) * loi_z[i]
        i = i +1
    var_z = var_z - pow(esp_z, 2)
    print
    print "esperance de X : {0:.3f}".format(esp_x)
    print "variance de X : {0:.3f}".format(var_x)
    print "esperance de Y : {0:.3f}".format(esp_y)
    print "variance de Y : {0:.3f}".format(var_y)
    print "esperance de Z : {0:.3f}".format(esp_z)
    print "variance de Z : {0:.3f}".format(var_z)

def     affichage_loi(loi_xy, loi_z):

    print "     ", "X={0:.0f} ".format(loi_xy[0][1]), "X={0:.0f} ".format(loi_xy[0][2]), "X={0:.0f} ".format(loi_xy[0][3]), "X={0:.0f} ".format(loi_xy[0][4]), "X={0:.0f} ".format(loi_xy[0][5]), "Loi Y"
    print "Y={0:.0f} ".format(loi_xy[1][0]), "{0:.3f}".format(loi_xy[1][1]), "{0:.3f}".format(loi_xy[1][2]), "{0:.3f}".format(loi_xy[1][3]), "{0:.3f}".format(loi_xy[1][4]), "{0:.3f}".format(loi_xy[1][5]), "{0:.3f}".format(loi_xy[1][6])
    print "Y={0:.0f} ".format(loi_xy[2][0]), "{0:.3f}".format(loi_xy[2][1]), "{0:.3f}".format(loi_xy[2][2]), "{0:.3f}".format(loi_xy[2][3]), "{0:.3f}".format(loi_xy[2][4]), "{0:.3f}".format(loi_xy[2][5]), "{0:.3f}".format(loi_xy[2][6])
    print "Y={0:.0f} ".format(loi_xy[3][0]), "{0:.3f}".format(loi_xy[3][1]), "{0:.3f}".format(loi_xy[3][2]), "{0:.3f}".format(loi_xy[3][3]), "{0:.3f}".format(loi_xy[3][4]), "{0:.3f}".format(loi_xy[3][5]), "{0:.3f}".format(loi_xy[3][6])
    print "Y={0:.0f} ".format(loi_xy[4][0]), "{0:.3f}".format(loi_xy[4][1]), "{0:.3f}".format(loi_xy[4][2]), "{0:.3f}".format(loi_xy[4][3]), "{0:.3f}".format(loi_xy[4][4]), "{0:.3f}".format(loi_xy[4][5]), "{0:.3f}".format(loi_xy[4][6])
    print "Y={0:.0f} ".format(loi_xy[5][0]), "{0:.3f}".format(loi_xy[5][1]), "{0:.3f}".format(loi_xy[5][2]), "{0:.3f}".format(loi_xy[5][3]), "{0:.3f}".format(loi_xy[5][4]), "{0:.3f}".format(loi_xy[5][5]), "{0:.3f}".format(loi_xy[5][6])
    print "Loi X".format(loi_xy[6][0]), "{0:.3f}".format(loi_xy[6][1]), "{0:.3f}".format(loi_xy[6][2]), "{0:.3f}".format(loi_xy[6][3]), "{0:.3f}".format(loi_xy[6][4]), "{0:.3f}".format(loi_xy[6][5]), "{0:.3f}".format(loi_xy[6][6])

    print
    print "   z    20     30    40   50    60    70     80   90    100  total"
    print "p(Z=z)", "{0:.3f}".format(loi_z[0]), "{0:.3f}".format(loi_z[1]), "{0:.3f}".format(loi_z[2]), "{0:.3f}".format(loi_z[3]), "{0:.3f}".format(loi_z[4]), "{0:.3f}".format(loi_z[5]), "{0:.3f}".format(loi_z[6]), "{0:.3f}".format(loi_z[7]),"{0:.3f}".format(loi_z[8]),"{0:.3f}".format(loi_z[9])


def     complete_list(loi_xy, loi_z, a, b):
## Complete loi_xy
    # Complete the value of x, y 10 -> 50
    i = 1
    for i in range(6):
        loi_xy[0][i] = i * 10.0
        loi_xy[i][0] = i * 10.0
    # Complete the tab except the last line
    i = 1
    while i < 7:
        j = 1
        rslt = 0;
        while j < 7:
            if (j == 6 or i == 6):
                loi_xy[i][j] = rslt;
            else:
                loi_xy[i][j] = ((a - loi_xy[0][j]) * (b - loi_xy[i][0])) / ((5 * a - 150) * (5 * b - 150))
                rslt = rslt + loi_xy[i][j]
            j = j + 1
        i = i + 1
    #Complete the last line
    j = 1
    while j < 7:
        i = 1
        rslt = 0
        while i < 6:
            rslt = rslt + loi_xy[i][j]
            i = i + 1
        loi_xy[i][j] = rslt
        j = j + 1
    #Complete loi_z
    z = 2
    while z < 11:
        rslt = 0
        i = 1
        while i < 6:
            j = 1
            while j < 6:
                if ((i + j) == z):
                    rslt = rslt + loi_xy[i][j]
                j = j + 1
            i = i + 1
        loi_z.append(rslt)
        z = z + 1
    total = 0
    for i in range(9):
        total = total + loi_z[i]
    loi_z.append(total)

    affichage_loi(loi_xy, loi_z)
    esperance_variance(loi_xy, loi_z)

def     main():
    if (len(sys.argv) != 3):
        usage()
    elif (int(sys.argv[1]) < 50 or int(sys.argv[2]) < 50):
        usage()
    else:
        loi_xy = []
        loi_z = []
        for i in range(7):
            loi_xy.append([0] * 7)
        complete_list(loi_xy, loi_z, float(sys.argv[1]), float(sys.argv[2]))
if __name__=="__main__":
    main()







