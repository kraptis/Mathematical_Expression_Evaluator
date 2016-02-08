//
//  Divition_Node.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Divition_Node__
#define ____Divition_Node__

#include <iostream>
#include "Binary_Expr_Node.h"


class Divition_Node:public Binary_Expr_Node{
public:
    Divition_Node(void);
    virtual ~Divition_Node(void);
    
    //evaluation of a binary operator, the object is passed to the visitor
    //and the visitor stores the result
    virtual int accept(Expr_Node_Visitor & v);
    
    virtual int priority();
};

#endif /* defined(____Divition_Node__) */
