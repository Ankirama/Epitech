//
//  Operand.h
//  cpp_abstractvm
//
//  Created by Fabien Martinez on 18/02/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_abstractvm__Operand__
#define __cpp_abstractvm__Operand__

#include <vector>
#include <string>
#include <typeinfo>
#include "IOperand.hh"
#include "template_string.hh"
#include "CalculStack.hh"

template<typename T>
class Operand : public IOperand {
  public:
	virtual std::string const & toString() const; // Renvoie une string reprensentant l’instance
	virtual int getPrecision() const; // Renvoie la precision du type de l’instance
	virtual eOperandType getType() const; // Renvoie le type de l’instance. Voir plus bas
	virtual IOperand * operator+(const IOperand &rhs) const; // Somme
	virtual IOperand * operator-(const IOperand &rhs) const; // Difference
	virtual IOperand * operator*(const IOperand &rhs) const; // Produit
	virtual IOperand * operator/(const IOperand &rhs) const; // Quotient
	virtual IOperand * operator%(const IOperand &rhs) const; // Modulo
  
  Operand(eOperandType type, std::string const &value);
  Operand(IOperand const &copy);
  IOperand& operator=(IOperand const&);
  virtual ~Operand();
  
  private:
	std::string const	m_valueStr;
	int					m_precision;
	eOperandType		m_type;
	T					m_value;
};

template<class T>
Operand<T>::Operand(eOperandType type, std::string const &value) : m_valueStr(value) {
  this->m_precision = type;
  this->m_type = type;
  try {
	this->m_value = StringToNumber<T>(value);
  }
  catch (UnknownError const &error) {
	std::cerr << "Error in " << error.getComponent() << " : " << error.what() << std::endl;
	throw ErrorAbstract("template_string");
  }
}

template<class T>
Operand<T>::Operand(IOperand const& copy) : m_valueStr(copy.toString()), m_precision(copy.getPrecision()),
  m_type(copy.getType()), m_value(StringToNumber<T>(copy.toString())) {}

template<class T>
IOperand& Operand<T>::operator=(IOperand const& copy) {
  if (this != &copy) {
	this->m_valueStr = copy.toString();
	this->m_precision = copy.getPrecision();
	this->m_type = copy.getType();
	try {
	  this->m_value = StringToNumber<T>(copy.toString());
	}
	catch (UnknownError const &error) {
	  std::cerr << "Error in " << error.getComponent() << " : " << error.what() << std::endl;
	  throw ErrorAbstract("template_string");
	}
  }
  return *this;
}

template<class T>
Operand<T>::~Operand() {}

template<class T>
std::string const & Operand<T>::toString() const {return this->m_valueStr;}

template<class T>
int Operand<T>::getPrecision() const {return this->m_precision;}

template<class T>
eOperandType Operand<T>::getType() const {return this->m_type;}

template<class T>
IOperand * Operand<T>::operator+(const IOperand &rhs) const {
  IOperand	*res;
  eOperandType type;
  double	tmp;
  
  type = rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType();
  try {
    tmp =	StringToNumber<double>(rhs.toString());
  }
  catch (UnknownError const &error) {
    std::cerr << "Error in " << error.getComponent() << " : " << error.what() << std::endl;
    throw ErrorAbstract("template_string");
  }
  switch (type) {
  case Int8:
    res = (new Operand<char>(type, NumberToString<char>(this->m_value + tmp)));
    break;
  case Int16:
    res = (new Operand<short>(type, NumberToString<short>(this->m_value + tmp)));
    break;
  case Int32:
    res = (new Operand<int>(type, NumberToString<int>(this->m_value + tmp)));
    break;
  case Float:
    res = (new Operand<float>(type, NumberToString<float>(this->m_value + tmp)));
    break;
  default:
    res = (new Operand<double>(type, NumberToString<double>(this->m_value + tmp)));
    break;
  }
  if (tmp > 0 && this->m_value > 0 && (res->toString())[0] == '-')
    throw NumberError("Overflow detected", "Operand");
  else if (tmp < 0 && this->m_value < 0 && (res->toString())[0] != '-')
    throw NumberError("underflow detected", "Operand");
  return (res);
}

template<class T>
IOperand * Operand<T>::operator-(const IOperand &rhs) const {
  IOperand	*res;
  double	tmp;
  eOperandType type;
  
  type = rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType();
  try {
	tmp = StringToNumber<double>(rhs.toString());
  }
  catch (UnknownError const &error) {
	std::cerr << "Error in " << error.getComponent() << " : " << error.what() << std::endl;
	throw ErrorAbstract("template_string");
  }
  switch (type) {
	case Int8:
	  res = (new Operand<char>(type, NumberToString<char>(this->m_value - tmp)));
	  break;
	case Int16:
	  res = (new Operand<short>(type, NumberToString<short>(this->m_value - tmp)));
	  break;
	case Int32:
	  res = (new Operand<int>(type, NumberToString<int>(this->m_value - tmp)));
	  break;
	case Float:
	  res = (new Operand<float>(type, NumberToString<float>(this->m_value - tmp)));
	  break;
	default:
	  res = (new Operand<double>(type, NumberToString<double>(this->m_value - tmp)));
	  break;
  }
  if (tmp > 0 && this->m_value < 0 && (res->toString())[0] == '-')
	throw NumberError("Overflow detected", "Operand");
  else if (tmp < 0 && this->m_value > 0 && (res->toString())[0] != '-')
	throw NumberError("Underflow detected", "Operand");
  return (res);
}

template<class T>
IOperand * Operand<T>::operator*(const IOperand &rhs) const {
  IOperand	*res;
  IOperand	*tmp_res;
  double	tmp;
  eOperandType type;
  
  type = rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType();
  try {
	tmp = StringToNumber<double>(rhs.toString());
	switch (type) {
	  case Int8:
		res = (new Operand<char>(type, NumberToString<char>(this->m_value * tmp)));
		tmp_res = (new Operand<char>(type, NumberToString<char>(tmp == 0 ? this->m_value : StringToNumber<char>(res->toString()) / tmp)));
		break;
	  case Int16:
		res = (new Operand<short>(type, NumberToString<short>(this->m_value * tmp)));
		tmp_res = (new Operand<char>(type, NumberToString<short>(tmp == 0 ? this->m_value : StringToNumber<short>(res->toString()) / tmp)));
		break;
	  case Int32:
		res = (new Operand<int>(type, NumberToString<int>(this->m_value * tmp)));
		tmp_res = (new Operand<char>(type, NumberToString<int>(tmp == 0 ? this->m_value : StringToNumber<int>(res->toString()) / tmp)));
		break;
	  case Float:
		res = (new Operand<float>(type, NumberToString<float>(this->m_value * tmp)));
		tmp_res = (new Operand<char>(type, NumberToString<float>(tmp == 0 ? this->m_value : StringToNumber<float>(res->toString()) / tmp)));
		break;
	  default:
		res = (new Operand<double>(type, NumberToString<double>(this->m_value * tmp)));
		tmp_res = (new Operand<char>(type, NumberToString<double>(tmp == 0 ? this->m_value : StringToNumber<double>(res->toString()) / tmp)));
		break;
	}
	if (StringToNumber<double>(tmp_res->toString()) != StringToNumber<double>(this->toString())) {
	  if (this->m_value < 0 || tmp < 0) {
		throw NumberError("Underflow detected", "Operand");
		delete tmp_res;
	  }
	  else {
		throw NumberError("Overflow detected", "Operand");
		delete tmp_res;
	  }
	}
	else {
	  delete tmp_res;
	  return (res);
	}
  }
  catch (ErrorAbstract const &error) {
	std::cerr << "Error in " << error.getComponent() << " : " << error.what() << std::endl;
	throw ErrorAbstract("Operand");
  }
}

template<class T>
IOperand * Operand<T>::operator/(const IOperand &rhs) const {
  IOperand	*res;
  double	tmp;
  eOperandType type;
  
  type = rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType();
  try {
	tmp = StringToNumber<double>(rhs.toString());
  }
  catch (UnknownError const &error) {
	std::cerr << "Error in " << error.getComponent() << " : " << error.what() << std::endl;
	throw ErrorAbstract("template_string");
  }
  if (tmp == 0)
	throw NumberError("Division by 0", "Component");
  switch (type) {
	case Int8:
	  res = (new Operand<char>(type, NumberToString<char>(this->m_value / tmp)));
	  break;
	case Int16:
	  res = (new Operand<short>(type, NumberToString<short>(this->m_value / tmp)));
	  break;
	case Int32:
	  res = (new Operand<int>(type, NumberToString<int>(this->m_value / tmp)));
	  break;
	case Float:
	  res = (new Operand<float>(type, NumberToString<float>(this->m_value / tmp)));
	  break;
	default:
	  res = (new Operand<double>(type, NumberToString<double>(this->m_value / tmp)));
	  break;
  }
  if (((this->m_value > 0 && tmp > 0) || (this->m_value < 0 && tmp < 0)) && res->toString()[0] == '-')
    throw NumberError("Overflow detected", "Operand");
  else if (((this->m_value > 0 && tmp < 0) || (this->m_value < 0 && tmp > 0)) && res->toString()[0] != '-')
    throw NumberError("Underflow detected", "Operand");
  return (res);
}

template<class T>
IOperand * Operand<T>::operator%(const IOperand &rhs) const {
  IOperand	*res;
  int	tmp;
  eOperandType type;
  
  type = rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType();
  if (type == Float || type == Double)
	throw NumberError("Modulo by decimal", "Operand");
  try {
	tmp = StringToNumber<int>(rhs.toString());
  }
  catch (UnknownError const &error) {
	std::cerr << "Error in " << error.getComponent() << " : " << error.what() << std::endl;
	throw ErrorAbstract("template_string");
  }
  if (tmp == 0)
	throw NumberError("Modulo by 0", "Operand");
  switch (type) {
	case Int8:
	  res = (new Operand<char>(type, NumberToString<char>((char)this->m_value % tmp)));
	  break;
	case Int16:
	  res = (new Operand<short>(type, NumberToString<short>((short)this->m_value % tmp)));
	  break;
	default:
	  res = (new Operand<int>(type, NumberToString<int>((int)this->m_value % tmp)));
	  break;
  }
  return (res);
}

#endif /* defined(__cpp_abstractvm__Operand__) */
