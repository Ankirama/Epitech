//
// IPizza.hh for  in /home/teyssa_r/rendu/cpp_plazza/src/graphic
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Sun Apr 19 00:36:00 2015 Raphael Teyssandier
// Last update Wed Apr 22 16:14:26 2015 Alexandre Chenevier
//

#ifndef IPIZZA_H_
# define IPIZZA_H_

# include "Ingredient.hh"
# include <iostream>
# include <vector>

class	IPizza {
public:
  virtual ~IPizza() {}

  virtual void				setName(const std::string &) = 0;
  virtual std::string			getName() const = 0;
  virtual void				setTime(const int) = 0;
  virtual int				getTime() const = 0;
  virtual void				setIngredient(const std::vector<IIngredient *>) = 0;
  virtual std::vector<IIngredient *>	getIngredient() const = 0;
};

#endif /* !IPIZZA_H_ */
