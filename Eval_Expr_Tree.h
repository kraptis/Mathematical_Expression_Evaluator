//
//  Eval_Expr_Tree.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Eval_Expr_Tree__
#define ____Eval_Expr_Tree__

#include <iostream>
#include "Expr_Node_Visitor.h"
#include "Addition_Node.h"
#include "Number_Node.h"
#include "Subtraction_Node.h"
#include "Multiply_Node.h"
#include "Divition_Node.h"
#include "Percentage_Node.h"
#include "Parenthesis_Node.h"


class Eval_Expr_Tree:public Expr_Node_Visitor{
public:
    Eval_Expr_Tree(void);
    virtual ~Eval_Expr_Tree(void);
    
    virtual void Visit_Addition_Node ( Addition_Node & node);
    virtual void Visit_Number_Node ( Number_Node & node);
    virtual void Visit_Subtraction_Node ( Subtraction_Node & node);
    virtual void Visit_Multiply_Node ( Multiply_Node & node);
    virtual void Visit_Divition_Node ( Divition_Node & node);
    
    virtual void Visit_Percentage_Node ( Percentage_Node & node);
    
    virtual int result(void);

};

#endif /* defined(____Eval_Expr_Tree__) */
