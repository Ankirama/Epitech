#include <iostream>
#include "RegexIsFunny.hh"
#include "Splines.hh"

#define CHECK_ARGS(ARGS)	(ARGS == 7)

int	main(int argc, char **argv) {
  RegexIsFunny *regex = new RegexIsFunny();
  Splines	*spline;
  float	rayons[5];
  int	nbr_points;
  
  if (!CHECK_ARGS(argc)) {
    std::cerr << "NOT ENOUGH ARGS" << std::endl;
    exit (84);
  }

  for (int i = 1; i < argc - 1; ++i) {
    rayons[i - 1] = regex->checkRayon(argv[i]);
  }
  nbr_points = regex->checkNumber(argv[6]);
  spline = new Splines(rayons, nbr_points);
  spline->algorithm();
  spline->display_solution();
  spline->alg_rayons();
  return 0;  
}
