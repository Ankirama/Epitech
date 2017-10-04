#ifndef INC_309POLLUTION_POINTS_HH
#define INC_309POLLUTION_POINTS_HH

#include <iostream>

class Points {
public:
  Points() {
    _poll = 0;
    _wgt = 1;
  }

  ~Points() {
  }
  Points(int poll) {
    _poll = poll;
    _wgt = 5;
  }

  void	setPoll(int poll) { _poll = poll; }
  void	setWgt(int wgt) { _wgt = wgt; }
  int	getPoll() { return _poll; }
  int	getWgt() { return _wgt; }

  
private:
  int	_poll;
  int	_wgt;
};
std::ostream&	operator<<(std::ostream &os, Points &points);

#endif //INC_309POLLUTION_POINTS_HH
