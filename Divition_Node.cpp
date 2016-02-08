//
//  Divition_Node.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Divition_Node.h"


Divition_Node::Divition_Node()
{
    
}

Divition_Node::~Divition_Node()
{
    
}

int Divition_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Divition_Node(*this);
    
	return v.result();
}

int Divition_Node::priority()
{
	return 2;
}