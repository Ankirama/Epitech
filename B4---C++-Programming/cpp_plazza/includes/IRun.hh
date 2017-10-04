#ifndef IRUN_HH_
# define IRUN_HH_

#include "unistd.h"

class IRun {
public:
  virtual ~IRun() {}
  virtual void	*start_routine() = 0;
};

#endif /* !IRUN_HH_ */
