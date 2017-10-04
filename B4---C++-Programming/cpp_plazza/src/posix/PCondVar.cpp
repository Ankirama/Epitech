#include "PCondVar.hh"

PCondVar::PCondVar(pthread_condattr_t *cond_attr, pthread_mutexattr_t *mutex_attr) {
  if (pthread_cond_init(&(this->m_cond), cond_attr) != 0)
    throw ErrorCondVar("Unable to init condition variable", "PCondVar");
  if (pthread_mutex_init(&(this->m_mutex), mutex_attr) != 0)
    throw ErrorMutex("Unable to init mutex", "PMutex");
}

PCondVar::~PCondVar() {
  if (pthread_cond_destroy(&(this->m_cond)) != 0)
    throw ErrorCondVar("Unable to destroy condition variable", "PCondVar");
  if (pthread_mutex_destroy(&(this->m_mutex)) != 0)
    throw ErrorMutex("Unable to destroy mutex", "PMutex");
}

void	PCondVar::wait() {
  if (pthread_mutex_lock(&(this->m_mutex)) != 0)
    throw ErrorMutex("Unable to lock mutex", "PMutex");
  if (pthread_cond_wait(&(this->m_cond), &(this->m_mutex)) != 0)
    throw ErrorCondVar("Unable to wait condition variable", "PCondVar");
  if (pthread_mutex_unlock(&(this->m_mutex)) != 0)
    throw ErrorMutex("Unable to unlock mutex", "PMutex");
}

void	PCondVar::signal() {
  if (pthread_cond_signal(&(this->m_cond)) != 0)
    throw ErrorCondVar("Unable to signal condition variable", "PCondVar");
}

void	PCondVar::broadcast() {
  if (pthread_cond_broadcast(&(this->m_cond)) != 0)
    throw ErrorCondVar("Unable to broadcast condition variable", "PCondVar");
}
