//
//  Subtract_Command.cpp
//  
//
//  Created by Dinos Raptis on 3/13/15.
//
//

#include "Subtract_Command.h"


Subtract_Command::Subtract_Command(void)
{
    
}


Subtract_Command::~Subtract_Command(void)
{
    
}



int Subtract_Command::priority()
{
    return 1;
}

int Subtract_Command::evaluate(int n1, int n2)
{
    return n1-n2;
}