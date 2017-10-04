#ifndef PMUTEX_HH_
# define PMUTEX_HH_

# include <pthread.h>
# include <iostream>
# include <errno.h>

# include "IMutex.hh"
# include "Error.hpp"

class PMutex : public IMutex {
public:
  explicit PMutex(pthread_mutexattr_t *attr = 0);
  virtual ~PMutex();

  virtual void	lock();
  virtual bool	trylock();
  virtual void	unlock();

  virtual pthread_mutex_t getMutex() const;

private:
  pthread_mutex_t	m_mutex;
private:
  PMutex& operator=(const PMutex&);
};

#endif /* !PMUTEX_HH_ */
