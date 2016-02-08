//
//  Parenthesis_Node.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Parenthesis_Node__
#define ____Parenthesis_Node__

#include <iostream>
#include "Binary_Expr_Node.h"


class Parenthesis_Node:public Binary_Expr_Node{
public:
    Parenthesis_Node(void);
    virtual ~Parenthesis_Node(void);
    
    virtual int accept(Expr_Node_Visitor & v);
    
    virtual int priority();
};

#endif /* defined(____Parenthesis_Node__) */
