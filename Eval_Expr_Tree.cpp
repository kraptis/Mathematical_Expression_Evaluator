//
//  Eval_Expr_Tree.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Eval_Expr_Tree.h"
#include <stdexcept>


Eval_Expr_Tree::Eval_Expr_Tree()
{
}

Eval_Expr_Tree::~Eval_Expr_Tree()
{
}

void Eval_Expr_Tree::Visit_Addition_Node ( Addition_Node & node)
{
	//It is more convinient if the accept method returns a value,  
    	// the visitor visits the node and instead to evaluate the result it can be immediately calculated
    	
    	
	result_ = node.getleftChild().accept(*this) + node.getrightChild().accept(*this);
}

void Eval_Expr_Tree::Visit_Number_Node(Number_Node &node)
{
	result_ = node.getNumber();
}

void Eval_Expr_Tree::Visit_Subtraction_Node(Subtraction_Node & node)
{
	result_ = node.getleftChild().accept(*this) - node.getrightChild().accept(*this);
}



void Eval_Expr_Tree::Visit_Multiply_Node(Multiply_Node & node)
{
	result_ = (node.getleftChild().accept(*this) * node.getrightChild().accept(*this));
}

void Eval_Expr_Tree::Visit_Divition_Node(Divition_Node & node)
{
    //check if the node that devides is zero, then return and give a new expression
    if(node.getrightChild().accept(*this) == 0)
	{
        std::cout << "can't be devided by zero \n";
        //throw std::logic_error ("can't be devided by zero");
        return;
    }
	result_ = (int)(node.getleftChild().accept(*this) / node.getrightChild().accept(*this));
    
}

void Eval_Expr_Tree::Visit_Percentage_Node(Percentage_Node & node)
{
	//check if the node that devides is zero, then return and give a new expression
    if(node.getrightChild().accept(*this) == 0)
	{
        std::cout << "can't be devided by zero \n";
        //throw std::logic_error ("can't be devided by zero");
        return;
    }
	result_ =(int)(node.getleftChild().accept(*this) % node.getrightChild().accept(*this));
}

int Eval_Expr_Tree::result()
{
	return this->result_;
}
