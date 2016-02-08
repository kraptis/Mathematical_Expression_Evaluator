//
//  Stack_Expr_Command_Factory.h
//  
//
//  Created by Dinos Raptis on 3/6/15.
//
//

#ifndef ____Stack_Expr_Command_Factory__
#define ____Stack_Expr_Command_Factory__

#include <iostream>
#include "Expr_Command_Factory.h"
/*
#include "Expr_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Number_Command.h"
#include "Multiply_Command.h"
#include "Devide_Command.h"
#include "Parenthesis_Command.h"
#include "Percentage_Command.h"*/



class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:
    Stack_Expr_Command_Factory(void);
    virtual ~Stack_Expr_Command_Factory (void);
    virtual Number_Command * create_number_command (int num);
    virtual Add_Command * create_add_command (void);
    virtual Subtract_Command * create_subtract_command (void);
    virtual Multiply_Command * create_multiply_command (void);
    
    virtual Devide_Command * create_devide_command (void);
    
    virtual Percentage_Command * create_percentage_command (void);
    
    virtual Parenthesis_Command * create_parenthesis_command (void);
    
    //virtual Parenthesis_Command * create_right_parenthesis_command (void);
    
private:
    // prevent the following operations
    
    //Stack_Expr_Command_Factory (const Stack_Expr_Command_Factory &);
    
    //const Stack_Expr_Command_Factory & operator = (const Stack_Expr_Command_Factory &);
    
};

#endif /* defined(____Stack_Expr_Command_Factory__) */
