//
//  Multiply_Node.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Multiply_Node__
#define ____Multiply_Node__

#include <iostream>
#include "Binary_Expr_Node.h"


class Multiply_Node:public Binary_Expr_Node{
public:
    Multiply_Node(void);
    virtual ~Multiply_Node(void);
    
    virtual int accept(Expr_Node_Visitor & v);
    
    virtual int priority();
};

#endif /* defined(____Multiply_Node__) */
