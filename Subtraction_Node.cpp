//
//  Subtraction_Node.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Subtraction_Node.h"


Subtraction_Node::Subtraction_Node()
{
    
}

Subtraction_Node::~Subtraction_Node()
{
}

int Subtraction_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Subtraction_Node(*this);
    
	return v.result();
}

int Subtraction_Node::priority()
{
	return 1;
}