//
// IConveyorBelt.hh for IConveyorBelt in /home/chenev_d/rendu/cpp_santa
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sat Jan 17 11:37:45 2015 Alexandre Chenevier
// Last update Sat Jan 17 12:14:24 2015 CHARLES VITERBO
//

#ifndef	ICONVEYORBELT_HH_
# define ICONVEYORBELT_HH_

class	IConveyorBelt
{
public:
  virtual ~IConveyorBelt();

  virtual void		Put(Object *) = 0;
  virtual Object *	Take() = 0;
  virtual std::string	&Look() = 0;
  virtual void		Button(int) = 0;
};

#endif /* !ICONVEYORBELT_HH_ */
