//
// TablePePeNoel.hh for TablePePeNoel in /home/chenev_d/rendu/cpp_santa
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sat Jan 17 11:30:39 2015 Alexandre Chenevier
// Last update Sat Jan 17 11:31:13 2015 Alexandre Chenevier
//

#ifndef	TABLEPEPENOEL_HH_
# define TABLEPEPENOEL_HH_

#include <string>
#include <vector>
#include "ITable.hh"
#include "Object.hh"
#include "Box.hh"
#include "GiftPaper.hh"
#include "LittlePony.hh"
#include "Teddy.hh"

class	TablePePeNoel : public ITable
{
private:
    std::vector<Object *> m_objects;
    int                 m_nbrObjects;
public:
    /* constructors */
    TablePePeNoel();
    TablePePeNoel(Object *toy1, Object *toy2);
    TablePePeNoel(TablePePeNoel const&);
    TablePePeNoel& operator=(TablePePeNoel const&);
    
    /* destructor */
    virtual ~TablePePeNoel();
    
    virtual void        Put(Object*);
    virtual Object      *Take(Object const&);
    virtual std::string *Look();
};

#endif /* !TABLEPEPENOEL_HH_ */
