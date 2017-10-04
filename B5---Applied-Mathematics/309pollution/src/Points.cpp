#include "Points.hh"

std::ostream&	operator<<(std::ostream& os, Points &points) {
  os << " " << points.getPoll() << "&" << points.getWgt() << " ";
};
