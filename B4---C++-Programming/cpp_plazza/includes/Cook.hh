#ifndef COOK_HH_
# define COOK_HH_

#include <vector>
#include <string>
#include "IRun.hh"
#include "Log.hh"
#include "PMutex.hh"
#include "PThread.hh"
#include "PCondVar.hh"
#include "Ingredient.hh"
#include "Stock.hh"
#include "Pizza.hh"
#include "PScopedLock.hh"

typedef enum	cookState {
  WAITING,
  COOKING,
  DELIVERING,
  LEAVING
}		cookState;

class Cook : public IRun {
public:
  explicit Cook(float cookingTime, ICondVar *cond,
		IMutex *mutex, Stock &stock,
		std::vector<IPizza *> &pizzas);
  virtual ~Cook();

  virtual void	*start_routine();
  cookState	getState();
private:
  float				m_cookingTime;
  cookState			m_state;
  ICondVar			*m_cond;
  IMutex			*m_mutex;
  Stock				&m_stock;
  std::vector<IPizza *>		&m_pizzas;
  IThread			*m_thread;
  PScopedLock			*m_scoped;
  IPizza			*m_pizza;
private:
  Cook& operator=(const Cook&);
};

#endif /* !COOK_HH_ */
