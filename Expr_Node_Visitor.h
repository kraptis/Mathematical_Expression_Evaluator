//
//  Expr_Node_Visitor.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Expr_Node_Visitor__
#define ____Expr_Node_Visitor__

#include <iostream>
class Addition_Node;
class Subtraction_Node;
class Number_Node;
class Multiply_Node;
class Divition_Node;
class Percentage_Node;



class Expr_Node_Visitor{
    
public:
    Expr_Node_Visitor();
    virtual ~Expr_Node_Visitor();
    
    virtual void Visit_Addition_Node (Addition_Node & node)=0;
    virtual void Visit_Number_Node (Number_Node & node)=0;
    virtual void Visit_Subtraction_Node (Subtraction_Node & node)=0;
    virtual void Visit_Multiply_Node (Multiply_Node & node)=0;
    virtual void Visit_Divition_Node (Divition_Node & node)=0;
    virtual void Visit_Percentage_Node (Percentage_Node & node)=0;
    
    virtual int result(void)=0;
    
protected:
    int result_;
    
};

#endif /* defined(____Expr_Node_Visitor__) */
