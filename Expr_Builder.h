//
//  Expr_Builder.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Expr_Builder__
#define ____Expr_Builder__

#include <iostream>
#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Stack.h"
#include "Array.h"
#include "Number_Node.h"


class Expr_Builder{
public:
    
    Expr_Builder(void);
    virtual ~Expr_Builder(void);
    
    
    
    virtual void build_expression (void)=0;
    virtual void checkpriority(Stack<Expr_Node *>& operators,Stack<Expr_Node *>& numbers, Expr_Node * rootNode,Expr_Node * expr_node)=0;
    virtual void build_number (int n) = 0;
    virtual void build_addition_operand (void) = 0;
    virtual void build_subtraction_operand (void) = 0;
    
    virtual void build_multiply_operand (void) = 0;
    
    virtual void build_divition_operand (void) = 0;
    
    virtual void build_percentage_operand (void) = 0;
    
    virtual void build_open_parenthesis (void) = 0;
    virtual void build_close_parenthesis (void) = 0;
    
    
    virtual Expr_Node * get_expression (void) = 0;
    
    
    // push a number_node to stack number
    void push(Expr_Node * n);
    
    
    Expr_Node* getTopNumber();
    
    Expr_Node* getTopOperator();
    
    
    void popOperator();
	
    void popNumber();
    
    bool isOperatorsEmpty();
    
    bool isNumbersEmpty();
    
    
    
    
protected:
    // current state of expression tree
    Expr_Node * tree_;
    // other variables to coordinate build process
    Stack<Expr_Node *> numbers;
	Stack<Expr_Node *> operators;
};


#endif /* defined(____Expr_Builder__) */
