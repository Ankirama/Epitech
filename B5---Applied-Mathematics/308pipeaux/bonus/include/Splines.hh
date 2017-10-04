#ifndef INC_308PIPEAUX_SPLINES_HH
#define INC_308PIPEAUX_SPLINES_HH

# define N	5
#include <stdio.h>
#include <cmath>
#include <chplot.h>

class Splines {
public:
  Splines() {}
  Splines(float *, int);
  ~Splines() {}
  
  void	display_solution();
  void	algorithm();
  void	alg_rayons();
  
private:
  int	m_points;
  float	*rayons;
  float	**m_matrice;
  float	m_solution[N];
  float	*x;
  float	*y;
  
  void	_gauss_elim();
  void	_substitution();
  void	_display_value(int);
  float	_value_rayon(float);
};

#endif //INC_308PIPEAUX_SPLINES_HH
