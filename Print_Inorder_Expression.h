//
//  Print_Inorder_Expression.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Print_Inorder_Expression__
#define ____Print_Inorder_Expression__

#include <iostream>
#include "Expr_Node_Visitor"

class Print_Inorder_Expression : public Expr_Node_Visitor {
public:
    Print_Inorder_Expression (std::ostream & out);
    
    virtual ~Print_Inorder_Expression (void);
    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node (Addition_Node & node)=0;
    virtual void Visit_Subtraction_Node (Subtraction_Node & node)=0;
    virtual void Visit_Number_Node (Number_Node & node)=0;
    virtual void Visit_Divition_Node (Divition_Node & node)=0;
    virtual void Visit_Multiply_Node (Multiply_Node & node)=0;
    virtual void Visit_Percentage_Node (Percentage_Node & node)=0;
private:
    // output stream
    std::ostream out_;
};

#endif /* defined(____Print_Inorder_Expression__) */
