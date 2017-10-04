#ifndef PTHREAD_HH_
# define PTHREAD_HH_

#include <pthread.h>
#include "Error.hpp"
#include "IThread.hh"
#include "IRun.hh"

class PThread : public IThread {
public:
  explicit PThread(IRun &obj, pthread_attr_t *attr = 0);
  virtual ~PThread();

  virtual stateThread	getState() const;
  virtual void		*start_routine();

private:
  stateThread		m_state;
  pthread_attr_t	*m_attr;
  IRun			&m_obj;
  pthread_t		m_thread;
private:
  PThread& operator=(const PThread&);
};

#endif /* !PTHREAD_HH_ */
