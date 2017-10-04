#ifndef PCONDVAR_HH_
# define PCONDVAR_HH_

# include <pthread.h>

# include "ICondVar.hh"
# include "IMutex.hh"
# include "Error.hpp"

class PCondVar : public ICondVar {
public:
  explicit PCondVar(pthread_condattr_t *cond_attr = 0, pthread_mutexattr_t *mut_attr = 0);
  virtual ~PCondVar();

  virtual void	wait();
  virtual void	signal();
  virtual void	broadcast();

private:
  pthread_cond_t	m_cond;
  pthread_mutex_t	m_mutex;
private:
  PCondVar& operator=(const PCondVar&);
};

#endif /* !PCONDVAR_HH_ */
