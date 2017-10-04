#ifndef INGREDIENT_HH_
# define INGREDIENT_HH_

#include <iostream>
#include <sstream>
#include "Log.hh"
#include "IIngredient.hh"

#define	DEFAULT_QUANTITY	5

class Ingredient : public IIngredient {
public:
  explicit Ingredient(std::string const &name, int quantity = DEFAULT_QUANTITY);
  virtual ~Ingredient();

  virtual int getQuantity() const;
  virtual bool setQuantity(int quantity);
  virtual bool removeQuantity(int quantity);
  virtual void resetIngredient();
  virtual std::string const &getName() const;
private:
  int		const m_defaultQuantity;
  std::string	m_name;
  int		m_quantity;
private:
  Ingredient& operator=(const Ingredient&);
};

#endif /* !INGREDIENT_HH_ */
