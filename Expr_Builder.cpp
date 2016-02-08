//
//  Expr_Builder.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Expr_Builder.h"


Expr_Builder::Expr_Builder()
: tree_(),numbers(),operators()
{
    
}

Expr_Builder::~Expr_Builder()
{
    
}

void Expr_Builder::push(Expr_Node * n)
{
	this->numbers.push(n);
}

Expr_Node* Expr_Builder::getTopOperator()
{
	return this->operators.top();
}

Expr_Node* Expr_Builder::getTopNumber()
{
	return this->numbers.top();
}

void Expr_Builder::popOperator()
{
	this->operators.pop();
}

void Expr_Builder::popNumber()
{
	this->numbers.pop();
}

bool Expr_Builder::isOperatorsEmpty()
{
    if(operators.size()!=0)
        return false;
    else
        true;
}

bool Expr_Builder::isNumbersEmpty()
{
	
    if(numbers.size()!=0)
        return false;
    else
        true;
}


