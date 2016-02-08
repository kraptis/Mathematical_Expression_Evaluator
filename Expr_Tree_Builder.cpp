//
//  Expr_Tree_Builder.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"

Expr_Tree_Builder::Expr_Tree_Builder()
{
    
}

Expr_Tree_Builder::~Expr_Tree_Builder()
{
    
}



void Expr_Tree_Builder::build_number(int n)
{
    
	Expr_Node * node = new Number_Node(n);
    
	this->numbers.push(node);
    
}
void Expr_Tree_Builder:: build_addition_operand()
{
    Expr_Node * node= new Addition_Node();
    
	checkpriority(this->operators,this->numbers,this->tree_,node);
    
}
void Expr_Tree_Builder::build_subtraction_operand()
{
	Expr_Node * node = new Subtraction_Node();
    
	checkpriority(this->operators,this->numbers,this->tree_,node);
}
void Expr_Tree_Builder::build_multiply_operand()
{
	Expr_Node * node = new Multiply_Node();
    
	checkpriority(this->operators,this->numbers,this->tree_,node);
}

void Expr_Tree_Builder::build_divition_operand()
{
   
	Expr_Node * node = new Divition_Node();
	checkpriority(this->operators,this->numbers,this->tree_,node);
}

void Expr_Tree_Builder::build_percentage_operand()
{
	
	Expr_Node * node = new Percentage_Node();
	checkpriority(this->operators,this->numbers,this->tree_,node);
}

void Expr_Tree_Builder::build_open_parenthesis()
{
  
	Expr_Node * node = new Parenthesis_Node();
	checkpriority(this->operators,this->numbers, this->tree_,node);
}

void Expr_Tree_Builder::build_close_parenthesis()
{
    Eval_Expr_Tree t;
    
    while(!isOperatorsEmpty())
    {
        
        Binary_Expr_Node *node=(Binary_Expr_Node*)getTopOperator();
        popOperator();
        if(node->priority()==0)
        {
            delete node;
            break;
        }
        if(node->priority()!=0)
        {
            node->setrightChild(getTopNumber());
            popNumber();
            
            node->setleftChild(getTopNumber());
            popNumber();
            
            int n=node->accept(t);
            
            push(new Number_Node(n));
            
        }
        delete node;
        
    }
}


void Expr_Tree_Builder::build_expression()
{
    
	Eval_Expr_Tree t;
    
	Number_Node *node;
	while(operators.size()!=0)
	{
		Binary_Expr_Node * temp=(Binary_Expr_Node*) operators.top();
        
		//pop an operator from stack
		this->operators.pop();
        
        	
        	//set the children of the ooerator and pop from stack with the numbers node 
		temp->setrightChild(this->numbers.top());
        
		this->numbers.pop();
		
		temp->setleftChild(this->numbers.top());
        
		this->numbers.pop();
        
		//visit the node
		int n=temp->accept(t);
		
		//evaluate the number of the node
        	node=new Number_Node(temp->accept(t));
        
        	//push the result on stack numbet
		this->numbers.push(node);
        
        if(operators.size()==0)
		{
			tree_=temp;
			break;
		}
		else
		{
			delete temp;
		}
		
	}
	delete node;
	
}



void Expr_Tree_Builder::checkpriority(Stack<Expr_Node *>& operators,Stack<Expr_Node *>& numbers, Expr_Node * rootNode,Expr_Node * expr_node)
{
	
	//move the operators nodes(and their children) according to their priority 
	
	if(operators.size()==0)
	{
		rootNode = expr_node;
		
		operators.push(expr_node);
        return;
		
	}
	else
	{
		Expr_Node* tempnode = operators.top();
		if(expr_node->priority() == 0)
        {
			operators.push(expr_node);
    
            return;
        }
        
		if(tempnode->priority() < expr_node->priority())
        {
			operators.push(expr_node);
            
            return;
        }
		else
		{
			
			Eval_Expr_Tree nodeVisitor;
			
			while(expr_node->priority() <= tempnode->priority() && operators.size()!=0)
			{
                
				Binary_Expr_Node *tempOperator = (Binary_Expr_Node*)(operators.top());
                
				operators.pop();
                
				tempOperator->setrightChild(numbers.top());
				numbers.pop();
                
				tempOperator->setleftChild(numbers.top());
				numbers.pop();
                
				int n=tempOperator->accept(nodeVisitor);
				
				this->numbers.push(new Number_Node(n));
                
                
				if(operators.size()==0)
				{
					delete tempnode;
					break;
				}
				
				tempnode = operators.top();
				delete tempOperator;
                
			}
			rootNode = expr_node;
			operators.push(rootNode);
            
		}
		
	}
}

Expr_Node * Expr_Tree_Builder::get_expression()
{
	return this->tree_;
    
}


