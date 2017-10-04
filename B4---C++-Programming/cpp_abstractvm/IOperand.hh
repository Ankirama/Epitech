//
//  IOperand.hh
//  cpp_abstractvm
//
//  Created by Fabien Martinez on 18/02/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef cpp_abstractvm_IOperand_hh
#define cpp_abstractvm_IOperand_hh

#include <string>
#include <iostream>
#include "Errors.hh"

typedef enum e_eOperandType {
  Int8,
  Int16,
  Int32,
  Float,
  Double
} eOperandType;

class IOperand
{
  public:
	virtual std::string const & toString() const = 0; // Renvoie une string reprensentant l’instance
	virtual int getPrecision() const = 0; // Renvoie la precision du type de l’instance
	virtual eOperandType getType() const = 0; // Renvoie le type de l’instance. Voir plus bas
	virtual IOperand * operator+(const IOperand &rhs) const = 0; // Somme
	virtual IOperand * operator-(const IOperand &rhs) const = 0; // Difference
	virtual IOperand * operator*(const IOperand &rhs) const = 0; // Produit
	virtual IOperand * operator/(const IOperand &rhs) const = 0; // Quotient
	virtual IOperand * operator%(const IOperand &rhs) const = 0; // Modulo
	virtual ~IOperand() {}
};

#endif
