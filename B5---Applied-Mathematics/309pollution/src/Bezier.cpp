#include "Bezier.hh"

Bezier::Bezier(int size, float x, float y, std::vector<std::vector<int> > csvRst) {
  int	elt = 0;
  
  _size = size;
  printf("Size = %d\n", size);
  _x = (size - 1 - x) / (size - 1);
  printf("x = %f\n", _x);
  _y = (size - 1 - y) / (size - 1);
  printf("y = %f\n", _y);
  for (int i = 0; i < size; i++) {
    std::vector<float >	tmp;
    for (int j = 0; j < size; j++) {
      if (elt < csvRst.size() && csvRst[elt][0] == i && csvRst[elt][1] == j) {
	tmp.push_back(csvRst[elt][2]);
	elt++;
      }
      else
	tmp.push_back(0);
    }
    _mapPoll.push_back(tmp);
  }
};

float	Bezier::polBernstein(float t, int m, int k) {
  float	result;
  //  printf("FACTORIELLE : m = %d - %f / k = %d - %f/ m - k = %d - %f\n", m, factorielle(m), k, factorielle(k), m - k, factorielle(m-k));
  result = (factorielle(m) / (factorielle(k) * factorielle(m - k))) * pow(t, k) * pow(1.0 - t, m - k);
  printf("t = %f, m = %d, k = %d, resultat = %f\n", t, m, k, result);
  return (result);
};

float	Bezier::ratBezierLig(float t, int cons) {
  float	sum1 = 0;

  for (int i = 0; i < _size; i++) {
    sum1 = sum1 + (polBernstein(t, _size, i + 1) * _mapPoll[cons][i]);
  }
  return (sum1);
};

float	Bezier::ratBezierCol(float t, int cons) {
  float	sum1 = 0;
  
  for (int i = 0; i < _size; i++) {
    sum1 = sum1 + (polBernstein(t, _size, i + 1) * _mapPoints[i]);
  }
  return (sum1);
};

float	Bezier::algorithm() {
  float	tmp = 0;

  for (int i = 0; i < _size; i++) {
    for (int j = 0; j < _size; j++) {
      tmp = tmp + polBernstein(_x, _size, i + 1) * polBernstein(_y, _size, j + 1) * _mapPoll[i][j];
    }
  }
  printf("%.2f", tmp);
};
