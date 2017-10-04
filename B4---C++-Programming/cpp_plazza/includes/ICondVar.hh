#ifndef ICONDVAR_HH_
# define ICONDVAR_HH_

class ICondVar {
public:
  virtual ~ICondVar() {}
  virtual void	wait() = 0;
  virtual void	signal() = 0;
  virtual void	broadcast() = 0;
};

#endif /* !ICONDVAR_HH_ */
