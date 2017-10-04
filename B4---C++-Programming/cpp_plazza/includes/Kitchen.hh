#ifndef KITCHEN_HH_
# define KITCHEN_HH_

#include <vector>
#include <iostream>
#include "Ingredient.hh"
#include "Cook.hh"
#include "Stock.hh"
#include "PMutex.hh"
#include "PScopedLock.hh"
#include "Pizza.hh"

class Kitchen {
public:
  explicit Kitchen(int cookingTime, long replaceTime, int cooks,
		   std::vector<IIngredient *> ingredients);
  ~Kitchen();

  bool	addPizza(IPizza *pizza);
  void	displayIngredient();
private:
  int				m_cookingTime;
  long				m_replaceTime;
  int				m_nbCooks;
  IMutex			*m_mutex;
  ICondVar			*m_cond;
  Stock				*m_stock;
  std::vector<IPizza *>		m_pizzas;
  PScopedLock			*m_scoped;
  std::vector<Cook *>		m_cooks;
private:
  Kitchen& operator=(const Kitchen&);
};

#endif /* !KITCHEN_HH_ */
