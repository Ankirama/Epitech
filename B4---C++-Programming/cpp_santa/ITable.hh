//
// ITable.hh for ITable in /home/chenev_d/rendu/cpp_santa
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sat Jan 17 11:36:12 2015 Alexandre Chenevier
// Last update Sat Jan 17 11:37:14 2015 Alexandre Chenevier
//

#ifndef	ITABLE_HH_
# define ITABLE_HH_

#include <string>
#include "Object.hh"

class	ITable
{
public:
    virtual ~ITable;
    
    virtual void    Put(const Object*) = 0;
    virtual Object  *Take() = 0;
    virtual std::string *Look() const = 0;
};

#endif /* !ITABLE_HH_ */
