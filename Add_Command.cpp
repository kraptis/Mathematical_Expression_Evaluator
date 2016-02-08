//
//  Add_Command.cpp
//  
//
//  Created by Dinos Raptis on 3/13/15.
//
//

#include "Add_Command.h"


Add_Command::Add_Command(void)
{
    
}


Add_Command::~Add_Command(void)
{
    
}

int Add_Command::priority()
{
	//2nd priority against the other operators, parenthesis has the maximum priority 
    	return 1;
}

int Add_Command::evaluate(int n1,int n2)
{
    
	return (n1 + n2);
}
