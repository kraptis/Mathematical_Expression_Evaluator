//
//  Expr_Node.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Expr_Node__
#define ____Expr_Node__

#include <iostream>
#include "Expr_Node_Visitor.h"

class Expr_Node{
public:
    Expr_Node(void);
    virtual ~Expr_Node(void);
    
    //evaluation of a binary operator, the object is passed to the visitor
    //and the visitor stores the result
    virtual int accept (Expr_Node_Visitor & v) = 0;
   
    virtual int priority()=0;
    
    
};

#endif /* defined(____Expr_Node__) */
