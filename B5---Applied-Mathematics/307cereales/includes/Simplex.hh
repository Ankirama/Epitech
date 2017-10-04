#ifndef INC_307CEREALES_SIMPLEX_HH
#define INC_307CEREALES_SIMPLEX_HH

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

# define X_LEN	11
# define Y_LEN	5

class Simplex {
public:
  Simplex() {}
  ~Simplex() {}

  Simplex(float *, float *);

  int	algorithm();
  void	display_data();
  void	display_product();
  void	display_result(float *);
  
private:
  float	**m_data;
  int	m_pivot[2];
  int	m_product[5];
  
  bool	_stop();
  void	_find_pivot();
  void	_do_the_pivot(int, int);
};

#endif //INC_307CEREALES_SIMPLEX_HH
