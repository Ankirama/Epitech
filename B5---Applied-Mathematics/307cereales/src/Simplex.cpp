#include "Simplex.hh"
#include <stdlib.h>
#include <stdio.h>
#include "templateString.h"

Simplex::Simplex(float * price, float *quantity) {
  float	data[5][11] = {
    {1.0, 0.0, 1.0, 0.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, quantity[0]},
    {1.0, 2.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, quantity[1]},
    {2.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, quantity[2]},
    {0.0, 0.0, 3.0, 1.0, 2.0, 0.0, 0.0, 0.0, 1.0, 0.0, quantity[3]},
    {-price[0], -price[1], -price[2], -price[3], -price[4], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0}    
  };
  /*
  std::cout.setf(std::ios::fixed, std::ios::floatfield);
  */
  this->m_data = new float*[Y_LEN];
  for (int i = 0; i < Y_LEN; ++i) {
    this->m_data[i] = new float[X_LEN];
    for (int j = 0; j < X_LEN; ++j) {
      this->m_data[i][j] = data[i][j];
    }
  }
  this->m_pivot[0] = -1;
  this->m_pivot[1] = -1;
  this->m_product[0] = -1;
  this->m_product[1] = -1;
  this->m_product[2] = -1;
  this->m_product[3] = -1;
  this->m_product[4] = -1;
  
  std::cout << "ressources : " << quantity[0] << " E1, " << quantity[1] << " E2, " << quantity[2] << " E3, " << quantity[3] << " E4" << std::endl;
}


bool	Simplex::_stop() {
  int	rslt = 0;

  for (int i = 0; i < X_LEN; ++i) {
    if (this->m_data[Y_LEN - 1][i] < 0) {
      rslt++;
    }
  }
  return (rslt != 0 ? false : true);
}

void	Simplex::_find_pivot() {
  int	x_piv = -1;
  int	y_piv = -1;

  // Position en X du pivot
  float	min = this->m_data[Y_LEN - 1][0];
  x_piv = 0;
  for (int i = 0; i < X_LEN - 1; ++i) {
    if (this->m_data[Y_LEN - 1][i] < min) {
      min = this->m_data[Y_LEN - 1][i];
      x_piv = i;
    }
  }

  // Position en Y du pivot
  min = std::numeric_limits<float>::max();
  if (x_piv != -1) {
    for (int i = 0; i < Y_LEN - 1; ++i) {
      if (this->m_data[i][x_piv] != 0) {
	float tmp = this->m_data[i][X_LEN - 1] / this->m_data[i][x_piv];
	if (tmp >= 0 && tmp < min) {
	  y_piv = i;
	  min = tmp;
	}
      }
    }
  }
  this->m_pivot[0] = y_piv;
  this->m_pivot[1] = x_piv;		  
}

void	Simplex::_do_the_pivot(int y_piv, int x_piv) {
  float	pivot = this->m_data[y_piv][x_piv];
  
  // On divise la ligne du pivot par le pivot
  for (int i = 0; i < X_LEN; ++i) {
    this->m_data[y_piv][i] = this->m_data[y_piv][i] / pivot;
  }

  // Ligne par ligne
  for (int i = 0; i < Y_LEN; ++i) {
    if (i != y_piv) {
      pivot = this->m_data[i][x_piv];
      for (int j = 0; j < X_LEN; ++j) {
	this->m_data[i][j] = this->m_data[i][j] - this->m_data[y_piv][j] * pivot;
      }
    }
  }
}
  
int	Simplex::algorithm() {
  while (!this->_stop()) {
    this->_find_pivot();
    if (this->m_pivot[0] == -1 || this->m_pivot[1] == -1)
      return 1;
    this->_do_the_pivot(this->m_pivot[0], this->m_pivot[1]);
    this->m_product[this->m_pivot[0]] = this->m_pivot[1];
  }
  return 42;
}

void	Simplex::display_data() {
  for (int i = 0; i < Y_LEN; ++i) {
    for (int j = 0; j < X_LEN; ++j) {
      printf("%.2f\t", this->m_data[i][j]);
    }
    printf("\n");
  }
}

void	Simplex::display_product() {
  for (int i = 0; i < 5; ++i) {
    printf("%d\n", this->m_product[i]);
    //std::cout << this->m_product[i] << std::endl;
  }
}

static void _displayType(float value, float price, const char *type) {
  printf("%s:\t", type);
  if ((int)value >= 0 && (int)value < 2) {
    if (value == 0) printf("0 unité \t");
    else printf("%.2f unité \t", value);
  }
  else {
    printf("%.2f unités\t", value);
  }
  printf("à %.0f €/unité\n", price);
}

void	Simplex::display_result(float *price) {
  float	value[5] = {0, 0, 0, 0, 0};
  
  for (int index = 0; index < 6; ++index) {
    for (int i = 0; i < 5; ++i) {
      if (this->m_product[i] == index)
	value[index] = this->m_data[i][X_LEN - 1];
    }
  }
  printf("\n");
  _displayType(value[0], price[0], "avoine");
  _displayType(value[1], price[1], "blé");
  _displayType(value[2], price[2], "maïs");
  _displayType(value[3], price[3], "orge");
  _displayType(value[4], price[4], "soja");
//  // avoine
//  std::cout << "avoine:\t";
//  if (value[0] == 0)
//    std::cout << "0 unité\t\t";
//  else {
//    std::cout << value[0] << " unités\t";
//  }
//  std::cout << "à " << price[0] << " €/unité" << std::endl;
//
//
//  // blé
//  std::cout << "blé:\t";
//  if (value[1] == 0)
//    std::cout << "0 unité\t\t";
//  else {
//    std::cout << value[1] << " unités\t";
//  }
//  std::cout << "à " << price[1] << " €/unité" << std::endl;
//
//
//  // maïs
//  std::cout << "maïs:\t";
//  if (value[2] == 0)
//    std::cout << "0 unité\t\t";
//  else
//    std::cout << value[2] << " unités\t";
//  std::cout << "à " << price[2] << " €/unité" << std::endl;
//
//
//  // orge
//  std::cout << "orge:\t";
//  if (value[3] == 0)
//    std::cout << "0 unité\t\t";
//  else
//    std::cout << value[3] << " unités\t";
//  std::cout << "à " << price[3] << " €/unité" << std::endl;
//
//
//  // soja
//  std::cout << "soja:\t";
//  if (value[4] == 0)
//    std::cout << "0 unité\t\t";
//  else
//    std::cout << value[4] << " unités\t";
//  std::cout << "à " << price[4] << " €/unité" << std::endl;

  printf("\nvaleur totale de la production : %.2f €\n", this->m_data[Y_LEN - 1][X_LEN - 1]);
}
