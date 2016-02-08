//
//  Subtract_Command.h
//  
//
//  Created by Dinos Raptis on 3/12/15.
//
//

#ifndef _Subtract_Command_h
#define _Subtract_Command_h

#include "Binary_Op_Command.h"

class Subtract_Command : public Binary_Op_Command {
public:
    Subtract_Command(void);
    virtual ~Subtract_Command(void);
    
    virtual int priority();
    virtual int evaluate (int n1, int n2);
private:
    
};

#endif
