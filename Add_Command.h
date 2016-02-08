//
//  Add_Command.h
//  
//
//  Created by Dinos Raptis on 3/12/15.
//
//

#ifndef _Add_Command_h
#define _Add_Command_h

#include "Binary_Op_Command.h"

// the addition command
class Add_Command : public Binary_Op_Command {
public:
    Add_Command(void);
    virtual ~Add_Command(void);
    //virtual bool execute (Stack<int> s);
    
    virtual int priority();
    virtual int evaluate(int n1, int n2);
private:
    
};

#endif
