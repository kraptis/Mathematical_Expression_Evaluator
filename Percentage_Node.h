//
//  Percentage_Node.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Percentage_Node__
#define ____Percentage_Node__

#include <iostream>
#include "Binary_Expr_Node.h"


class Percentage_Node:public Binary_Expr_Node{
public:
    Percentage_Node(void);
    virtual ~Percentage_Node(void);
    
    virtual int accept(Expr_Node_Visitor & v);
    
    virtual int priority();
};

#endif /* defined(____Percentage_Node__) */
