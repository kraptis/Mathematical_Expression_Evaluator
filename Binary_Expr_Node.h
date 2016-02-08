//
//  Binary_Expr_Node.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Binary_Expr_Node__
#define ____Binary_Expr_Node__

#include <iostream>
#include "Expr_Node_Visitor.h"
#include "Expr_Node.h"

class Binary_Expr_Node:public Expr_Node{
  
public:
    
    Binary_Expr_Node();
    virtual ~Binary_Expr_Node();
    
    //evaluation of a binary operator, the object is passed to the visitor
    //and the visitor stores the result
    virtual int accept(Expr_Node_Visitor & v)=0;
    
    Expr_Node & getrightChild(void);
    Expr_Node & getleftChild(void);
    Expr_Node & setleftChild(Expr_Node * node);
    Expr_Node & setrightChild(Expr_Node * node);
    
    
    virtual int priority()=0;
    
    
    
protected:
    //right and left node(children) of a node
    Expr_Node * right_;
    Expr_Node * left_;

};

#endif /* defined(____Binary_Expr_Node__) */
