//
//  Multiply_Command.h
//  
//
//  Created by Dinos Raptis on 3/12/15.
//
//

#ifndef _Multiply_Command_h
#define _Multiply_Command_h

#include "Binary_Op_Command.h"

class Multiply_Command : public Binary_Op_Command {
public:
    Multiply_Command(void);
    virtual ~Multiply_Command(void);
    
    virtual int priority();
    virtual int evaluate (int n1, int n2);
private:
   
};

#endif
