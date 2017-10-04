#include "PScopedLock.hh"
#include "Log.hh"

PScopedLock::PScopedLock(IMutex *mutex): m_mutex(mutex) {
  try {
    this->m_mutex->lock();
  }
  catch (ErrorMutex const& e) {
    Log::getInstance().writeError(e.what(), e.getComponent());
    throw ErrorPlazza(e.what(), e.getComponent());
  }
}

PScopedLock::~PScopedLock() {
  try {
    this->m_mutex->unlock();
  }
  catch (ErrorMutex const& e) {
    Log::getInstance().writeError(e.what(), e.getComponent());
  }
}
