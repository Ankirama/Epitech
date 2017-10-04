#ifndef STOCK_HH_
# define STOCK_HH_

#include <vector>
#include <unistd.h>
#include "PThread.hh"
#include "Ingredient.hh"
#include "IRun.hh"
#include "PMutex.hh"
#include "PScopedLock.hh"

class Stock : public IRun {
public:
  Stock(long replaceTime, std::vector<IIngredient *> ingredients, IMutex *mutex);
  virtual ~Stock();
  virtual void	*start_routine();
  void	setStatus(bool running); 
  std::vector<IIngredient *> &getIngredients();
  bool	removeQuantity(std::string const& ingredient, int quantity);
private:
  IThread			*m_thread;
  std::vector<IIngredient *>	m_ingredients;
  bool				m_running;
  IMutex			*m_mutex;
  long				m_replaceTime;
  PScopedLock			*m_scoped;
};

#endif /* !STOCK_HH_ */
