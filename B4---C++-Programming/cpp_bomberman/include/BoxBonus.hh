#ifndef	BOXBONUS_HH_
# define BOXBONUS_HH_

#include "Animation.hh"
#include <cstdlib>
#include <iostream>
#include <ctime>

class BoxBonus
{
private:
  unsigned int	m_position;
  std::string	m_bonus;
  Animation	*m_animation;

  //  BoxBonus();

public:
  // Constructor
  BoxBonus(unsigned int);

  //Destructor
  ~BoxBonus();

  //Getter
  Animation	*getAnimation() const;
  unsigned int	getPosition();
  std::string	getBonus();

  //Setter
  void		setPosition(unsigned int);
};

#endif /* !BOXBONUS_HH_ */
