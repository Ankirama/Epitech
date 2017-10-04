//
//  CalculStack.h
//  cpp_abstractvm
//
//  Created by Fabien Martinez on 20/02/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_abstractvm__CalculStack__
#define __cpp_abstractvm__CalculStack__

#include <fstream>
#include <stdlib.h>
#include "Operand.hh"

# define	NB_CMD	11
# define	NB_TYPE	5

class CalculStack {
public:
  CalculStack();
  ~CalculStack();
  IOperand * createOperand(eOperandType type, const std::string & value) const;

  void		on_file(char *str);
  void		on_standard();

private:
  IOperand * createInt8(const std::string & value) const;
  IOperand * createInt16(const std::string & value) const;
  IOperand * createInt32(const std::string & value) const;
  IOperand * createFloat(const std::string & value) const;
  IOperand * createDouble(const std::string & value) const;

  typedef IOperand *		(CalculStack::*createPtr)(const std::string &) const;
  typedef void			(CalculStack::*parserPtr)(const std::string &);
  typedef struct		s_avm{
    std::string      		name;
    parserPtr			fun;
  }				t_avm;

  t_avm				m_avm_tab[NB_CMD];
  std::vector<IOperand*>	list;
  createPtr			m_arrPtr[5];

  void		avm_push(const std::string &);
  void		avm_pop(const std::string &);
  void		avm_dump(const std::string &);
  void		avm_assert(const std::string &);
  void		avm_add(const std::string &);
  void		avm_sub(const std::string &);
  void		avm_mul(const std::string &);
  void		avm_div(const std::string &);
  void		avm_mod(const std::string &);
  void		avm_print(const std::string &);
  void		avm_exit(const std::string &);

  void		check_fl_db(const std::string &);
  void		check_error(const std::string &, unsigned int);
  void		check_pu_as(const std::string &);
  void		exec_list_cmd(std::vector<std::string> &);
  void		which_cmd(const std::string &);
};

#endif /* defined(__cpp_abstractvm__CalculStack__) */
