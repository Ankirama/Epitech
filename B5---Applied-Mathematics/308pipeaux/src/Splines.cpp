#include "Splines.hh"
#include <iostream>

Splines::Splines(float *rayon, int number) {
  this->m_points = number;
  /*
   * On construit la matrice (valeur calculée à la main car toujours les memes)
   */
  float	m_data[5][5] = {{1.0, 0.0, 0.0, 0.0, 0.0},
		  {0.5, 2.0, 0.5, 0.0, 0.0},
		  {0.0, 0.5, 2.0, 0.5, 0.0},
		  {0.0, 0.0, 0.5, 2.0, 0.5},
		  {0.0, 0.0, 0.0, 0.0, 1.0}};

  this->rayons = rayon;
  /*
   * On construit le vecteur F de AX = F (formule déduite du cours)
   */
  this->m_solution[0] = 0.0;
  for (int i = 1; i < N - 1; i++) {
    this->m_solution[i] = 6.0 * (rayon[i + 1] - 2.0 * rayon[i] + rayon[i - 1]) / 50.0;
  }
  this->m_solution[N - 1] = 0.0;

  /*
   * On construit notre matrice à partir du tableau statique
   */
  this->m_matrice = new float*[N];
  for (int i = 0; i < N; i++) {
    this->m_matrice[i] = new float[N];
    for (int j = 0; j < N; j++) {
      this->m_matrice[i][j] = m_data[i][j];
    }
  }
}


void	Splines::_gauss_elim() {
  /*
   * Elimination gaussienne, pas besoin de faire de pivot car on aura jamais de 0 sur la diagonale
   */
  float	ratio = 0;
  for (int i = 0; i < (N - 1); i++) {
    for (int j = (i + 1); j < N; j++) {
      ratio = this->m_matrice[j][i] / this->m_matrice[i][i];
      for (int k = i; k < N; k++) {
	this->m_matrice[j][k] -= (ratio * this->m_matrice[i][k]);
      }
      this->m_solution[j] -= (ratio * this->m_solution[i]);
    }
  }
}
				   
void	Splines::_substitution() {
  float	tmp;
  this->m_solution[N - 1] = this->m_solution[N - 1] / this->m_matrice[N - 1][N - 1];;
  for (int i = N - 2; i >= 0; i--) {
    tmp = this->m_solution[i];
    for (int j = (i + 1); j < N; j++) {
      tmp -= (this->m_matrice[i][j] * this->m_solution[j]);
    }
    this->m_solution[i] = tmp / this->m_matrice[i][i];
  }
}

void	Splines::algorithm() {
  this->_gauss_elim();
  this->_substitution();
}

void	Splines::_display_value(int i) {
  float	min = -0.05;
  float max = 0.01;

  if ((this->m_solution[i] > min && this->m_solution[i] < max) && i < N - 1)
    printf("%.1f, ", fabs(this->m_solution[i]));
  else if (i < N - 1)
    printf("%.1f, ", this->m_solution[i]);
  else
      printf("%.1f", this->m_solution[i]);
}

void	Splines::display_solution() {
  printf("vecteur résultat : [");
  for (int i = 0; i < N; i++)
    this->_display_value(i);
  printf("]\n");
}

float	Splines::_value_rayon(float x) {
  float xi;
  float	xi_1;
  float	fi;
  float	fi_1;
  float	d2fi;
  float	d2fi_1;
  
  if (x >= 0.0 && x < 5.0) {
    xi_1 = 0.0;
    xi = 5.0;
    d2fi_1 = this->m_solution[0];
    d2fi = this->m_solution[1];
    fi_1 = this->rayons[0];
    fi = this->rayons[1];
  }
  else if (x >= 5.0 && x < 10.0) {
    xi_1 = 5.0;
    xi = 10.0;
    d2fi_1 = this->m_solution[1];
    d2fi = this->m_solution[2];
    fi_1 = this->rayons[1];
    fi = this->rayons[2];
  }
  else if (x >= 10.0 && x < 15.0) {
    xi_1 = 10;
    xi = 15.0;
    d2fi_1 = this->m_solution[2];
    d2fi = this->m_solution[3];
    fi_1 = this->rayons[2];
    fi = this->rayons[3];
  }
  else if (x >= 15.0 && x <= 20.0) {
    xi_1 = 15.0;
    xi = 20.0;
    d2fi_1 = this->m_solution[3];
    d2fi = this->m_solution[4];
    fi_1 = this->rayons[3];
    fi = this->rayons[4];
  }
  return (- d2fi_1 * pow(x - xi, 3) / 30.0 + d2fi * pow(x - xi_1, 3) / 30.0 - ((fi_1 / 5.0) - 5.0 * d2fi_1 / 6.0) * (x - xi) + (fi / 5.0 - 5.0 * d2fi / 6.0) * (x - xi_1)); 
}

void	Splines::alg_rayons() {
  float	inter = 20.0 / (this->m_points - 1);
  for (float x = 0; x <= 20.0; x = x + inter) {
    printf("abscisse : %.1f cm\trayon : %.1f cm\n", x, _value_rayon(x));
  }
}
