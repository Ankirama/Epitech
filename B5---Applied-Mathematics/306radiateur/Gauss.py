from Error import *

class Gauss:
    '''
    Gauss' class : fuck you
    '''
    def __init__(self, list_arg, mode):
        self.mode = mode
        self.size = list_arg[0]
        self.i_rad = list_arg[1]
        self.j_rad = list_arg[2]
        if self.mode == False:
            self.i_room = list_arg[3]
            self.j_room = list_arg[4]
        self.matrix = list()
        self.vector_temp = list()
        self.solution = list()
        '''
        Constantes
        '''
        self._h = 0.25
        self._f = -300
        '''
        Verification valeurs
        '''
        if self.size <= 0:
            error_message("The room's size must be > 0 !")
        elif (self.i_rad < 1 or self.i_rad > self.size - 2) or (self.j_rad < 1 or self.j_rad > self.size - 2) :
            error_message("Radiator's coordinates must be between 0 and %s !" % (self.size - 2))
        elif (self.mode == False and ((self.i_room < 1 or self.i_room > self.size - 2) or (self.j_room < 1 or self.j_room > self.size - 2))):
            error_message("Room's coordinates must be between 0 and %s !" % self.size)

    '''
    Initialize matrix
    '''
    def build_matrix(self):
        matrix_size = self.size * self.size
        for y in range(0, self.size):
            for x in range(0, self.size):
                if (y == 0 or y == self.size - 1 or x == 0 or x == self.size - 1):
                    self.matrix.append(self._cond_limite(x, y, matrix_size))
                else:
                    self.matrix.append(self._cond_eq(x, y, matrix_size))

    '''
    Initialize vector
    '''
    def build_vector(self):
        for j in range(self.size):
            for i in range(self.size):
                if (i == self.i_rad and j == self.j_rad):
                    self.vector_temp.append(self._f)
                else:
                    self.vector_temp.append(0)

    def _cond_limite(self, x, y, matrix_size):
        line = list()
        diag = x + y * self.size
        for cpt in range(matrix_size):
            if (cpt != diag):
                line.append(0)
            else:
                line.append(1)
        return line
    
    def _cond_eq(self, x, y, matrix_size):
        line = list()
        diag = x + y * self.size
        for cpt in range(matrix_size):
            if (cpt == x - 1 + y * self.size or cpt == x + 1 + y * self.size or cpt == x + (y - 1) * self.size or cpt == x + (y + 1) * self.size):
                line.append(int(1 / self._h))
            elif (cpt == x + y * self.size):
                line.append(int(- 4 / self._h))
            else:
                line.append(0)
        return line

    def _swap_line(self, matrice, i, j):
        temp = matrice[i]
        matrice[i] = matrice[j]
        matrice[j] = temp

    def _ope_mat(self, matrice, i, j, coeff):
        if type(matrice[0]) != list:
            matrice[i] = matrice[i] + coeff * matrice[j]
        else:
            n = len(matrice[0])
            for k in range(n):
                matrice[i][k] = matrice[i][k] + coeff * matrice[j][k]

    def _find_max(self, matrice, j):
        n = len(matrice)
        imax = j
        for i in range(j + 1, n ):
            if abs(matrice[i][j]) > abs(matrice[imax][j]):
                imax = i
        return imax

    def _triangle(self, matrice, vector):
        n = len(vector)
        x = [0 for i in range(n)]
        x[n - 1] = vector[n - 1] / matrice[n - 1][n - 1]
        for i in range(n - 2, -1, -1):
            s = 0
            for j in range(i + 1, n):
                s = s + matrice[i][j] * x[j]
            x[i] = (vector[i] - s) / matrice[i][i]
        return x

    def solution_sys(self):
        matrice = self.matrix
        vector = self.vector_temp
        n = len(matrice)
        i = 0
        for i in range(n-1):
            pivot = self._find_max(matrice, i)
            self._swap_line(matrice, i, pivot)
            self._swap_line(vector, i, pivot)
            for k in range(i + 1, n ):
                x = float(matrice[k][i] / matrice[i][i])
                self._ope_mat(matrice, k, i, -x)
                self._ope_mat(vector, k, i, -x)
        self.solution =  self._triangle(matrice, vector)
         
    '''
    Display matrix
    '''
    def display_matrix(self):
        if self.mode == True:
            matrix_size = self.size * self.size
            for line in self.matrix:
                i = 0
                for elt in line:
                    i += 1
                    if (i < matrix_size):
                        print("%d\t" % elt),
                    else:
                        print("%d" % elt)
        
    '''
    Display vector
    '''
    def display_temp(self):
        if self.mode == True:
            for elt in self.solution:
                tmp = round(round(elt, 2) * 100)
                if (tmp % 10 == 5):
                    tmp += 1
                tmp /= 100
                if (tmp > -0.04 and tmp < 0.01):
                    tmp = abs(tmp)
                print ('%.1f' % tmp)
        else:
            tmp = round(round(self.solution[self.i_room + self.j_room * self.size], 2) * 100)
            if (tmp % 10 == 5):
                tmp += 1
            tmp /= 100
            if (tmp > -0.04 and tmp < 0.01):
                tmp = abs(tmp)
            print ('%.1f' % tmp)
