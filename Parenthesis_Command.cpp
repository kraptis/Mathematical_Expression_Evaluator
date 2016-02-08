//
//  Parenthesis_Command.cpp
//  
//
//  Created by Dinos Raptis on 3/13/15.
//
//

#include "Parenthesis_Command.h"


Parenthesis_Command::Parenthesis_Command(void)
{

}

Parenthesis_Command::~Parenthesis_Command(void)
{
    
}



int Parenthesis_Command::priority()
{
    // Maximum priority against the other operators		
    return 0;
}

bool Parenthesis_Command::execute(Stack<int> &s)
{
    return true;
}

int Parenthesis_Command::evaluate(int n1,int n2)
{
    //This method is never used, it is defined dor compiling reasons
	return (n1);
}
