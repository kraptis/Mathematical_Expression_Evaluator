//
//  Devide_Command.h
//  
//
//  Created by Dinos Raptis on 3/12/15.
//
//

#ifndef _Devide_Command_h
#define _Devide_Command_h

#include "Binary_Op_Command.h"

class Devide_Command : public Binary_Op_Command {
public:
    Devide_Command(void);
    virtual ~Devide_Command(void);
    
    virtual int priority();
    virtual int evaluate(int n1, int n2);
private:
    
};


#endif
