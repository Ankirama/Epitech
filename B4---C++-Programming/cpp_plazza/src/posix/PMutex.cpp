#include "PMutex.hh"

PMutex::PMutex(pthread_mutexattr_t *attr) {
  if (pthread_mutex_init(&(this->m_mutex), attr) != 0)
    throw ErrorMutex("Unable to init mutex", "PMutex");
}

PMutex::~PMutex() {
  if (pthread_mutex_destroy(&(this->m_mutex)) != 0)
    throw ErrorMutex("Unable to destroy mutex", "PMutex");
}

void		PMutex::lock() {
  if (pthread_mutex_lock(&(this->m_mutex)) != 0)
    throw ErrorMutex("Unable to lock mutex", "PMutex");
}

bool		PMutex::trylock() {
  int		error_value;

  if ((error_value = pthread_mutex_trylock(&(this->m_mutex))) == EBUSY)
    return (false);
  else if (error_value != 0)
    throw ErrorMutex("Unable to trylock mutex", "PMutex");
  return (true);
}

void		PMutex::unlock() {
  if (pthread_mutex_unlock(&(this->m_mutex)) != 0)
    throw ErrorMutex("Unable to unlock mutex", "PMutex");
}

pthread_mutex_t	PMutex::getMutex() const {return this->m_mutex;}
