//
//  Parenthesis_Command.h
//  
//
//  Created by Dinos Raptis on 3/12/15.
//
//

#ifndef _Parenthesis_Command_h
#define _Parenthesis_Command_h

#include "Binary_Op_Command.h"

class Parenthesis_Command : public Binary_Op_Command {
public:
    Parenthesis_Command(void);
    virtual ~Parenthesis_Command(void);
    
    virtual int priority();
    virtual bool execute (Stack <int> &s);
    
    virtual int evaluate(int n1, int n2);
private:
    
    
};


#endif
