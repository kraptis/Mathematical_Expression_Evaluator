//
//  Number_Node.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Number_Node__
#define ____Number_Node__

#include <iostream>
#include "Binary_Expr_Node.h"


class Number_Node:public Binary_Expr_Node{
public:
    Number_Node(int n);
    virtual ~Number_Node(void);
    
    virtual int accept(Expr_Node_Visitor & v);
    
    virtual int priority();
    
    int getNumber();
    
private:
    int n_;
};

#endif /* defined(____Number_Node__) */
