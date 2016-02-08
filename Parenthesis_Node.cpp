//
//  Parenthesis_Node.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Parenthesis_Node.h"


Parenthesis_Node::Parenthesis_Node()
{
}

Parenthesis_Node::~Parenthesis_Node()
{
	
}

int Parenthesis_Node::accept(Expr_Node_Visitor &v)
{
	return 0;
}

int Parenthesis_Node::priority()
{
	return 0;
}