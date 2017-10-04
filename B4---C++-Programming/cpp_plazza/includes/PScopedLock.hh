#ifndef PSCOPEDLOCK_HH
# define PSCOPEDLOCK_HH

# include <iostream>
# include <pthread.h>
# include "IMutex.hh"
# include "Error.hpp"

class PScopedLock {
public:
  explicit PScopedLock(IMutex *mutex);
  ~PScopedLock();

private:
  PScopedLock& operator=(PScopedLock const&);

  IMutex	*m_mutex;
};

#endif /* !PSCOPEDLOCK_HH */
