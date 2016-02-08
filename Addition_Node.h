//
//  Addition_Node.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Addition_Node__
#define ____Addition_Node__

#include <iostream>
#include "Binary_Expr_Node.h"


class Addition_Node:public Binary_Expr_Node{
public:
    Addition_Node(void);
    virtual ~Addition_Node(void);
    
    //evaluation of a binary operator, the object is passed to the visitor
    //and the visitor stores the result
    //when the visitors visits an operand node like addition node, it stores the result of the children
    //according to the operator node, here is +
    virtual int accept(Expr_Node_Visitor & v);
    
    virtual int priority();
};

#endif /* defined(____Addition_Node__) */
