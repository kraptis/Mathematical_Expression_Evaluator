//
//  Number_Command.h
//  
//
//  Created by Dinos Raptis on 3/12/15.
//
//

#ifndef _Number_Command_h
#define _Number_Command_h

#include "Binary_Op_Command.h"

class Number_Command : public Binary_Op_Command {
public:
    Number_Command(void);
    Number_Command(int n);
    virtual ~Number_Command(void);
   
    virtual bool execute (Stack <int> &s);
    
    virtual int evaluate(int n1, int n2);
    
     virtual int priority();
    
    
private:
    
    int n_;
    
};

#endif
