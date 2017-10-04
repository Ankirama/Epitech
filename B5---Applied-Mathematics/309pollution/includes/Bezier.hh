#ifndef INC_309POLLUTION_BEZIER_HH
#define INC_309POLLUTION_BEZIER_HH

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

class Bezier {
public:
  Bezier(int, float, float, std::vector<std::vector<int> >);
  ~Bezier();

  float	polBernstein(float, int, int);
  float	ratBezierLig(float, int);
  float	ratBezierCol(float, int);
  float	algorithm();
  
private:
  std::vector<std::vector<float > >	_mapPoll;
  std::vector<float >	_mapPoints;
  int	_size;
  float	_x;
  float	_y;

private:
  float	factorielle(int n) {
    return ((n >= 1) ? n * factorielle(n - 1) : 1);
  }

  float	getReste(float n) {
    return (n - (int)n);
  }
};

#endif //INC_309POLLUTION_BEZIER_HH
  
