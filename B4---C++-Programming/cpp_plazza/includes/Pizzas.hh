#ifndef PIZZAS_HH_
# define PIZZAS_HH_

#include <vector>
#include <string>
#include <algorithm>
#include "Log.hh"
#include "Error.hpp"
#include "Pizza.hh"

class Pizzas {
public:
  static Pizzas& getInstance();
  IPizza *getPizza(std::string const&);
  void addPizza(std::string const&, const int, const std::vector<IIngredient *>);
  std::vector<IPizza *>	getAllPizza() const;
private:
  Pizzas& operator=(const Pizzas&);
  Pizzas(const Pizzas&) {}

  Pizzas();
  ~Pizzas();
private:
  static Pizzas		m_instance;
  std::vector<IPizza *>	m_pizzas;
};

#endif /* !PIZZAS_HH_ */
