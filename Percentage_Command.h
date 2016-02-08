//
//  Percentage_Command.h
//  
//
//  Created by Dinos Raptis on 3/12/15.
//
//

#ifndef _Percentage_Command_h
#define _Percentage_Command_h

#include "Binary_Op_Command.h"

class Percentage_Command : public Binary_Op_Command {
public:
    Percentage_Command(void);
    virtual ~Percentage_Command(void);
    
    virtual int priority();
    virtual int evaluate (int n1,int n2);
private:
    
};

#endif
