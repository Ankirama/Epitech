#ifndef ITHREAD_HH_
# define ITHREAD_HH_

typedef enum	stateThread {
  PENDING,
  ALIVE,
  DEAD
}		stateThread;

class IThread {
public:
  virtual ~IThread() {}
  virtual stateThread	getState() const = 0;
  virtual void		*start_routine() = 0;
};

#endif /* !ITHREAD_HH_ */
