//
//  Binary_Op_Command.h
//  
//
//  Created by Dinos Raptis on 3/9/15.
//
//

#ifndef ____Binary_Op_Command__
#define ____Binary_Op_Command__

#include <iostream>
#include "Expr_Command.h"


class Binary_Op_Command: public Expr_Command
{
	
     public:
    
	
	Binary_Op_Command();
    
	
	virtual ~Binary_Op_Command();
    
    
	//it executes the necessary evaluation
	virtual bool execute(Stack <int> &s);
    
        //evaluates (addition, multiplication etc. two integers)
	virtual int evaluate (int n1,int n2)=0;
    
        virtual int priority()=0;
    
	
    
    
};

#endif /* defined(____Binary_Op_Command__) */
