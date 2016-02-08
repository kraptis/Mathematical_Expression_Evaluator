//
//  Percentage_Command.cpp
//  
//
//  Created by Dinos Raptis on 3/13/15.
//
//

#include "Percentage_Command.h"


Percentage_Command::Percentage_Command(void)
{
    
}


Percentage_Command::~Percentage_Command(void)
{
    
}


int Percentage_Command::priority()
{
    return 2;
}

int Percentage_Command::evaluate(int n1,int n2)
{
    if(n2==0){
        std::cout << "can't be devided by zero \n";
        throw std::logic_error ("can't be devided by zero");
    }
    return n1%n2;
}
