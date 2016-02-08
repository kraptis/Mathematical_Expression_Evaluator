//
//  Number_Command.cpp
//  
//
//  Created by Dinos Raptis on 3/13/15.
//
//

#include "Number_Command.h"


Number_Command::Number_Command(void)
{
    
}

Number_Command::Number_Command(int n)
:n_(n)
{
    
}


Number_Command::~Number_Command(void)
{
    
}





bool Number_Command::execute(Stack<int> &s)
{
    //std::cout << "\nakjsdhkjashd\n";
    //std::cout << n_;
    //std::cout << "\nakjsdhkjashd\n";
    s.push(n_);
    //std::cout << "\nakjsdhkjashd\n";
    //std::cout << "\nakjsdhkjashd\n";
    return true;
}

int Number_Command::priority()
{
    return -1;
}

int Number_Command::evaluate(int n1,int n2)
{
    
	return (n1);
}

