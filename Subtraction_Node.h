//
//  Subtraction_Node.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Subtraction_Node__
#define ____Subtraction_Node__

#include <iostream>
#include "Binary_Expr_Node.h"


class Subtraction_Node:public Binary_Expr_Node{
public:
    Subtraction_Node(void);
    virtual ~Subtraction_Node(void);
    
    virtual int accept(Expr_Node_Visitor & v);
    
    virtual int priority();
};

#endif /* defined(____Subtraction_Node__) */
