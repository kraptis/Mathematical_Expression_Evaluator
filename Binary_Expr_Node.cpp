//
//  Binary_Expr_Node.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Binary_Expr_Node.h"


Binary_Expr_Node::Binary_Expr_Node()
:right_(),left_()
{
    
}

Binary_Expr_Node::~Binary_Expr_Node()
{	
	delete this->left_;
	delete this->right_;
}


Expr_Node & Binary_Expr_Node::getleftChild()
{
	return *this->left_;
}

Expr_Node & Binary_Expr_Node::getrightChild()
{
	return *this->right_;
}

Expr_Node & Binary_Expr_Node:: setleftChild(Expr_Node *node)
{
	this->left_ = node;
}

Expr_Node & Binary_Expr_Node:: setrightChild(Expr_Node *node)
{
	this->right_ = node;
}





