//
//  Multiply_Node.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Multiply_Node.h"


Multiply_Node::Multiply_Node()
{
}

Multiply_Node::~Multiply_Node()
{
    
}

int Multiply_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Multiply_Node(*this);
    
	return v.result();
    
}

int Multiply_Node::priority()
{
	return 2;
}