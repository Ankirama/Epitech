#include "PThread.hh"
#include "Log.hh"

static void	*_start_routine(void *object) {
  PThread	*run;

  run = reinterpret_cast<PThread *>(object);
  if (run == 0)
    throw ErrorPlazza("Unable to reinterpret_cast", "PThread");
  return run->start_routine();
}

PThread::PThread(IRun &object, pthread_attr_t *attr) : m_state(PENDING), m_attr(attr), m_obj(object) {
  if (pthread_create(&(this->m_thread), this->m_attr, _start_routine, this) != 0)
    throw ErrorThread("unable to create a new thread", "PThread");
  this->m_state = ALIVE;
}

PThread::~PThread() {
  void	*retval;
  if (pthread_join(this->m_thread, &retval) != 0)
    throw ErrorThread("unable to join a thread", "PThread");
  this->m_state = DEAD;
}

stateThread	PThread::getState() const {
  return this->m_state;
}

void		*PThread::start_routine() {
  return this->m_obj.start_routine();
}
