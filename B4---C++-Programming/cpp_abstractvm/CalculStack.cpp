//
//  CalculStack.cpp
//  cpp_abstractvm
//
//  Created by Fabien Martinez on 20/02/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "CalculStack.hh"
#include <algorithm>

static std::string	tab_type[NB_TYPE] = {
  "int8",
  "int16",
  "int32",
  "float",
  "double"
};

CalculStack::CalculStack() {
  this->m_arrPtr[0] = &CalculStack::createInt8;
  this->m_arrPtr[1] = &CalculStack::createInt16;
  this->m_arrPtr[2] = &CalculStack::createInt32;
  this->m_arrPtr[3] = &CalculStack::createFloat;
  this->m_arrPtr[4] = &CalculStack::createDouble;
  this->m_avm_tab[0].name = std::string("avm_push");
  this->m_avm_tab[0].fun = &CalculStack::avm_push;
  this->m_avm_tab[1].name = std::string("avm_pop");
  this->m_avm_tab[1].fun = &CalculStack::avm_pop;
  this->m_avm_tab[2].name = std::string("avm_dump");
  this->m_avm_tab[2].fun = &CalculStack::avm_dump;
  this->m_avm_tab[3].name = std::string("avm_assert");
  this->m_avm_tab[3].fun = &CalculStack::avm_assert;
  this->m_avm_tab[4].name = std::string("avm_add");
  this->m_avm_tab[4].fun = &CalculStack::avm_add;
  this->m_avm_tab[5].name = std::string("avm_sub");
  this->m_avm_tab[5].fun = &CalculStack::avm_sub;
  this->m_avm_tab[6].name = std::string("avm_mul");
  this->m_avm_tab[6].fun = &CalculStack::avm_mul;
  this->m_avm_tab[7].name = std::string("avm_div");
  this->m_avm_tab[7].fun = &CalculStack::avm_div;
  this->m_avm_tab[8].name = std::string("avm_mod");
  this->m_avm_tab[8].fun = &CalculStack::avm_mod;
  this->m_avm_tab[9].name = std::string("avm_print");
  this->m_avm_tab[9].fun = &CalculStack::avm_print;
  this->m_avm_tab[10].name = std::string("avm_exit");
  this->m_avm_tab[10].fun = &CalculStack::avm_exit;
}
CalculStack::~CalculStack() {
  this->list.clear();
}

IOperand * CalculStack::createOperand(eOperandType type, const std::string & value) const {
  IOperand *ope;

  try {
	ope = (this->*m_arrPtr[type])(value);
  }
  catch (ErrorAbstract const& e) {
	throw ErrorAbstract(e.what());
  }
  return ope;
}
IOperand * CalculStack::createInt8(const std::string & value) const {
  IOperand *ope;

  try {
	ope = new Operand<char>(Int8, value);
  }
  catch (ErrorAbstract const& e) {
	throw ErrorAbstract(e.what());
  }
  return ope;
}
IOperand * CalculStack::createInt16(const std::string & value) const {
  IOperand *ope;

  try {
	ope = new Operand<short>(Int16, value);
  }
  catch (ErrorAbstract const& e) {
	throw ErrorAbstract(e.what());
  }
  return ope;
}
IOperand * CalculStack::createInt32(const std::string & value) const {
  IOperand *ope;

  try {
	ope = new Operand<int>(Int32, value);
  }
  catch (ErrorAbstract const& e) {
	throw ErrorAbstract(e.what());
  }
  return ope;
}
IOperand * CalculStack::createFloat(const std::string & value) const {
  IOperand *ope;

  try {
	ope = new Operand<float>(Float, value);
  }
  catch (ErrorAbstract const& e) {
	throw ErrorAbstract(e.what());
  }
  return ope;
}
IOperand * CalculStack::createDouble(const std::string & value) const {
  IOperand *ope;

  try {
    ope = new Operand<double>(Double, value);
  }
  catch (ErrorAbstract const& e) {
    throw ErrorAbstract(e.what());
  }
  return ope;
}

void		CalculStack::check_fl_db(const std::string & val){
  int		i = 0;
  int		tmp = i;

  if (val[i] && val[i] == '-')
    i++;
  while (val[i] && val[i] >= '0' && val[i] <= '9')
    i++;
  if (val[i] && i != 0)
    if (val[i] == '.'){
      tmp = ++i;
      while (val[i] && val[i] >= '0' && val[i] <= '9')
	i++;
      if (i == tmp)
	throw InstructionError("No number after point for decimal", "CalculStack");
    }else{
      throw InstructionError("The separator for decimal isn't '.'", "CalculStack");
    }
  else{
    throw InstructionError("No point for decimal value", "CalculStack");
  }
}

void		CalculStack::avm_push(const std::string & tmp){
  std::string	type;
  std::string	val;
  std::string	cmd;
  std::size_t	pos;
  CalculStack	*calc = new CalculStack();
  int		i = 0;

  pos = tmp.find(" ");
  if (pos != std::string::npos){
    cmd = tmp.substr(pos + 1, tmp.length());
    cmd.erase(std::remove(cmd.begin(), cmd.end(), '\t'), cmd.end());
    cmd.erase(remove_if(cmd.begin(), cmd.end(), isspace), cmd.end());
    pos = cmd.find("(");
    if (pos != std::string::npos){
      type = cmd.substr(0, pos);
      val = cmd.substr(pos + 1);
      val[(cmd.length() - 1) - (pos + 1)] = 0;
      while (i < NB_TYPE && tab_type[i] != type)
	i++;
      try {
	if (i == 3 || i == 4)
	  check_fl_db(val);
      }
      catch (InstructionError const& e){
	throw InstructionError(e.what(), e.getComponent());
      }
      try {
	if (i < NB_TYPE)
	  this->list.insert(this->list.begin(), calc->createOperand((eOperandType)i, val));
	else
	  throw InstructionError("Wrong type used", "CalculStack");
      }
      catch (InstructionError const& e) {
	std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
	throw ErrorAbstract("CalculStack");
      }
      catch (ErrorAbstract const& e) {
	throw ErrorAbstract(e.what());
      }
    }
  }
  else
    throw InstructionError("Problem with push instruction", "CalculStack");
}

void	CalculStack::avm_pop(const std::string & tmp){
  (void)tmp;
  if (this->list.empty())
    throw StackError("The list is empty", "CalculStack");
  this->list.erase(list.begin());
}

void	CalculStack::avm_dump(const std::string & tmp){
  (void)tmp;
  std::vector<IOperand*>::iterator	it = this->list.begin();
  IOperand				*val;

  if (this->list.empty())
    throw StackError("The list is empty", "CalculStack");
  while (it != this->list.end()){
    val = *it;
    std::cout << val->toString() << std::endl;
    it++;
  }
}

void	CalculStack::avm_assert(const std::string & tmp){
  (void)tmp;
  IOperand	*val_tmp;
  std::string	type;
  std::string	val;
  std::string	cmd;
  std::size_t	pos;
  int		i = Int8;

  if (this->list.empty())
    throw StackError("Not enough in the stack", "CalculStack");
  pos = tmp.find(" ");
  if (pos != std::string::npos){
    cmd = tmp.substr(pos + 1, tmp.length());
    cmd.erase(std::remove(cmd.begin(), cmd.end(), '\t'), cmd.end());
    cmd.erase(remove_if(cmd.begin(), cmd.end(), isspace), cmd.end());
    pos = cmd.find("(");
    if (pos != std::string::npos){
      type = cmd.substr(0, pos);
      val = cmd.substr(pos + 1);
      val[(cmd.length() - 1) - (pos + 1)] = 0;
      while (i < NB_TYPE && tab_type[i] != type)
	i++;
      try {
	if (i < NB_TYPE)
	  val_tmp = this->createOperand((eOperandType)i, val);
	else
	  throw InstructionError("Wrong type used", "CalculStack");
      }
      catch (InstructionError const& e) {
	std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
	throw ErrorAbstract("CalculStack");
      }
      catch (ErrorAbstract const& e) {
	throw ErrorAbstract(e.what());
      }
    }
     if (this->list.front()->getType() != val_tmp->getType()){
      throw AssertError("Wrong assert !", "Calculstack");
    }
    else if (this->list.front()->toString() != val_tmp->toString()){
      throw AssertError("Wrong assert !", "Calculstack");
    }
  }
}

void	CalculStack::avm_add(const std::string & tmp){
  (void)tmp;
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*val3;

  if (this->list.size() < 2)
    throw StackError("Not enough in the stack", "CalculStack");
  val1 = this->list.front();
  list.erase(this->list.begin());
  val2 = this->list.front();
  list.erase(this->list.begin());
  try {
    val3 = *val2 + *val1;
  }
  catch (NumberError const &e) {
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorAbstract("Operand");
  }
  catch (ErrorAbstract const& e) {
    throw ErrorAbstract(e.what());
  }
  this->list.insert(this->list.begin(), val3);
}

void	CalculStack::avm_sub(const std::string & tmp){
  (void)tmp;
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*val3;

  if (this->list.size() < 2)
    throw StackError("Not enough in the stack", "CalculStack");
  val1 = this->list.front();
  this->list.erase(this->list.begin());
  val2 = this->list.front();
  this->list.erase(this->list.begin());
  try {
    val3 = *val2 - *val1;
  }
  catch (NumberError const &e) {
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorAbstract("Operand");
  }
  catch (ErrorAbstract const& e) {
    throw ErrorAbstract(e.what());
  }
  this->list.insert(this->list.begin(), val3);
}

void	CalculStack::avm_mul(const std::string & tmp){
  (void)tmp;
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*val3;

  if (this->list.size() < 2)
    throw StackError("Not enough in the stack", "CalculStack");
  val1 = this->list.front();
  this->list.erase(this->list.begin());
  val2 = this->list.front();
  this->list.erase(this->list.begin());
  try {
    val3 = *val2 * *val1;
  }
  catch (NumberError const &e) {
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorAbstract("Operand");
  }
  catch (ErrorAbstract const& e) {
    throw ErrorAbstract(e.what());
  }
  this->list.insert(this->list.begin(), val3);
}

void	CalculStack::avm_div(const std::string & tmp){
  (void)tmp;
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*val3;

  if (this->list.size() < 2)
    throw StackError("Not enough in the stack", "CalculStack");
  val1 = this->list.front();
  this->list.erase(this->list.begin());
  val2 = this->list.front();
  this->list.erase(this->list.begin());
  try {
    val3 = *val2 / *val1;
  }
  catch (NumberError const &e) {
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorAbstract("Operand");
  }
  catch (ErrorAbstract const& e) {
    throw ErrorAbstract(e.what());
  }
  this->list.insert(this->list.begin(), val3);
}

void	CalculStack::avm_mod(const std::string & tmp){
  (void)tmp;
  IOperand	*val1;
  IOperand	*val2;
  IOperand	*val3;

  if (this->list.size() < 2)
    throw StackError("Not enough in the stack", "CalculStack");
  val1 = this->list.front();
  this->list.erase(this->list.begin());
  val2 = this->list.front();
  this->list.erase(this->list.begin());
  try {
    val3 = *val2 % *val1;
  }
  catch (NumberError const &e) {
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorAbstract("Operand");
  }
  catch (ErrorAbstract const& e) {
    throw ErrorAbstract(e.what());
  }
  this->list.insert(this->list.begin(), val3);
}

void	CalculStack::avm_print(const std::string & tmp){
  (void)tmp;
  IOperand	*val;
  long	ascii;

  if (this->list.empty())
    throw StackError("Not enough in the stack", "CalculStack");
 val = this->list.front();
  if (val->getType() != Int8)
    throw StackError("Wrong type (not Int8) to print it", "CalculStack");
  std::istringstream is(val->toString());
  is >> ascii;
  std::cout << (char)ascii << std::endl;
}

void	CalculStack::avm_exit(const std::string & tmp){
  (void)tmp;
  return;
}

void		CalculStack::check_error(const std::string & cmd, unsigned int i){
  if (i > 0){
    while (cmd[i] && (cmd[i] == 32 || cmd[i] == '\t'))
      i++;
    if (i < cmd.length())
      if (cmd[i] && cmd[i] != ';')
	throw InstructionError("Line not good", "CalculStack");
  }
}

void		CalculStack::check_pu_as(const std::string & cmd){
  std::size_t	pos;

  pos = cmd.find(")");
  if (pos != std::string::npos){
    pos++;
    while (cmd[pos] && (cmd[pos] == 32 || cmd[pos] == '\t'))
      pos++;
    if (pos < cmd.length())
      if (cmd[pos] && cmd[pos] != ';')
      throw InstructionError("Instruction not found", "CalculStack");
  }
}

void		CalculStack::which_cmd(const std::string & cmd){
  int		i = 0;
  std::size_t	pos;
  std::size_t	postab;
  std::string	tmp;

  pos = cmd.find(" ");
  postab = cmd.find("\t");
  if ((pos != std::string::npos && postab != std::string::npos) && pos < postab)
    tmp = "avm_" + cmd.substr(0, pos);
  else if ((pos != std::string::npos && postab != std::string::npos) && pos > postab)
    tmp = "avm_" + cmd.substr(0, postab);
  else if (pos != std::string::npos)
    tmp = "avm_" + cmd.substr(0, pos);
  else if (postab != std::string::npos)
    tmp = "avm_" + cmd.substr(0, postab);
  else
    tmp = "avm_" + cmd;
  while (i < NB_CMD && tmp != this->m_avm_tab[i].name){
    i++;
  }
  try {
    if (i != 0 && i != 3)
      this->check_error(cmd, tmp.length() - 4);
    else
      this->check_pu_as(cmd);
    if (i < NB_CMD && tmp == this->m_avm_tab[i].name)
      (this->*m_avm_tab[i].fun)(cmd);
    else
      throw InstructionError("Instruction not found", "CalculStack");
  }
  catch (StackError const &e) {
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorAbstract("StackError");
  }
  catch (AssertError const &e) {
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorAbstract("StackError");
  }
  catch (InstructionError const &e) {
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorAbstract("StackError");
  }
  catch (ErrorAbstract const &e) {
    throw ErrorAbstract(e.what());
  }
}

void	CalculStack::exec_list_cmd(std::vector<std::string> & list_cmd){
  std::vector<std::string>::const_iterator	it = list_cmd.begin();
  std::string					cmd;

  while (it != list_cmd.end()){
    try {
      this->which_cmd(*it);
    }
    catch (ErrorAbstract const &e) {
      throw ErrorAbstract(e.what());
    }
    it++;
  }
}

void				CalculStack::on_standard(){
  std::vector<std::string>	list_cmd;
  std::string			tmp = " ";
  std::string			leave = "";
  std::size_t			pos = 0;
  char				myexit = 0;

  while (tmp != ";;"){
    std::getline(std::cin, tmp);
    if (tmp[0] && tmp[0] != ';'){
      pos = tmp.find(";");
      if (pos != std::string::npos)
	tmp = tmp.substr(0, pos);
      leave = tmp;
      leave.erase(std::remove(leave.begin(), leave.end(), '\t'), leave.end());
      leave.erase(remove_if(leave.begin(), leave.end(), isspace), leave.end());
      if (leave == "exit")
	myexit = 1;
      if (myexit == 0)
	list_cmd.push_back(tmp);
    }
  }
  try {
    this->exec_list_cmd(list_cmd);
  }
  catch (ErrorAbstract const &e) {
    throw ErrorAbstract(e.what());
  }
  if (tmp == ";;")
    myexit = 1;
  if (myexit == 0){
    throw EndError("No exit found", "CalculStack");
  }
}

void				CalculStack::on_file(char *str){
  std::vector<std::string>	list_cmd;
  std::ifstream			file(str);
  std::string			leave = "";
  std::string			tmp = "";
  std::size_t			pos = 0;
  char				myexit = 0;

  if (file){
    while (file && leave != "exit"){
      getline(file, tmp);
      if (tmp[0] && tmp[0] != ';'){
	pos = tmp.find(";");
	if (pos != std::string::npos)
	  tmp = tmp.substr(0, pos);
	leave = tmp;
	leave.erase(std::remove(leave.begin(), leave.end(), '\t'), leave.end());
	leave.erase(remove_if(leave.begin(), leave.end(), isspace), leave.end());
	if (leave == "exit")
	  myexit = 1;
	list_cmd.push_back(tmp);
      }
    }
    try {
      this->exec_list_cmd(list_cmd);
    }
    catch (ErrorAbstract const &e) {
      throw ErrorAbstract(e.what());
    }
    if (myexit == 0){
      throw EndError("No exit found", "CalculStack");
    }
  }
}
