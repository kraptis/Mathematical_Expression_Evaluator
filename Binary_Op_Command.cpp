//
//  Binary_Op_Command.cpp
//  
//
//  Created by Dinos Raptis on 3/9/15.
//
//

#include "Binary_Op_Command.h"




Binary_Op_Command:: Binary_Op_Command()
{
    
}


Binary_Op_Command::~Binary_Op_Command()
{
    
}


bool Binary_Op_Command::execute(Stack<int> &s)
{
	
	int n2= s.top();
	s.pop();
    
	int n1= s.top();
	s.pop();
    
        int result = this->evaluate(n1,n2);
	s.push(result);
    
	return true;
}
