//
//  Devide_Command.cpp
//  
//
//  Created by Dinos Raptis on 3/13/15.
//
//

#include "Devide_Command.h"


Devide_Command::Devide_Command(void)
{
    
}


Devide_Command::~Devide_Command(void)
{
    
}



int Devide_Command::priority()
{
	return 2;
}

int Devide_Command::evaluate(int n1,int n2)
{
    
    if(n2==0){
        std::cout << "can't be devided by zero \n";
        throw std::logic_error ("can't be devided by zero");
    }
    int result;
	result= (int)n1 / n2;
    //std::cout << "\n";
    //std::cout << result;
	return result;
}