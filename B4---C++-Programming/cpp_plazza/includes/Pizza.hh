//
// Pizza.hh for  in /home/teyssa_r/rendu/cpp_plazza/src/graphic
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Sun Apr 19 00:54:38 2015 Raphael Teyssandier
// Last update Wed Apr 22 16:13:04 2015 Alexandre Chenevier
//

#ifndef PIZZA_HH_
# define PIZZA_HH_

# include "IPizza.hh"
# include "IIngredient.hh"

class	Pizza : public IPizza {
private:
  std::string			m_name;
  int				m_time;
  std::vector<IIngredient *>	m_ingredients;
private:
  Pizza& operator=(const Pizza&);

public:
  explicit Pizza(const std::string &, const int, const std::vector<IIngredient *>);
  ~Pizza();

  virtual void				setName(const std::string &);
  virtual std::string			getName() const;
  virtual void				setTime(const int);
  virtual int				getTime() const;
  virtual void				setIngredient(const std::vector<IIngredient *>);
  virtual std::vector<IIngredient *>	getIngredient() const;
};

#endif /* !PIZZA_HH_ */
