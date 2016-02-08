//
//  Addition_Node.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Addition_Node.h"

Addition_Node::Addition_Node()
{
    
}

Addition_Node::~Addition_Node()
{
	
}

int Addition_Node::accept(Expr_Node_Visitor & v)
{
	//the object is passed to the visitor
    	//the visitor stores the result
	v.Visit_Addition_Node(*this);
    
	return v.result();
}

int Addition_Node::priority()
{
	return 1;
}
