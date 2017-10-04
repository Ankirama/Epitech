#ifndef IMUTEX_HH_
# define IMUTEX_HH_

class IMutex {
public:
  virtual ~IMutex() {}

  virtual void lock() = 0;
  virtual bool trylock() = 0;
  virtual void unlock() = 0;
  virtual pthread_mutex_t getMutex() const = 0;
};

#endif /* !IMUTEX_HH_ */
