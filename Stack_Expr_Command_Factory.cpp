//
//  Stack_Expr_Command_Factory.cpp
//  
//
//  Created by Dinos Raptis on 3/6/15.
//
//

#include "Stack_Expr_Command_Factory.h"
/*#include "Expr_Command.h"
#include "Expr_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Number_Command.h"
#include "Multiply_Command.h"
#include "Devide_Command.h"
#include "Parenthesis_Command.h"
#include "Percentage_Command.h"*/


Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (void)
{
    
}

Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void)
{
    
}

Number_Command* Stack_Expr_Command_Factory::create_number_command (int num)
{
    //Number_Command * cmd=new Number_Command(num);
    return new Number_Command(num);
}

Add_Command* Stack_Expr_Command_Factory::create_add_command (void)
{
    //Add_Command *cmd = new Add_Command();
    return new Add_Command();
}

Subtract_Command* Stack_Expr_Command_Factory::create_subtract_command (void)
{
    //Subtract_Command* cmd=new Subtract_Command();
    return new Subtract_Command();
}

Multiply_Command* Stack_Expr_Command_Factory::create_multiply_command (void)
{
    //Multiply_Command* cmd=new Multiply_Command();
    return new Multiply_Command();
}

Devide_Command* Stack_Expr_Command_Factory::create_devide_command (void)
{
    //Devide_Command* cmd=new Devide_Command();
    return new Devide_Command();
}

Percentage_Command* Stack_Expr_Command_Factory::create_percentage_command (void)
{
    //Percentage_Command* cmd=new Percentage_Command();
    return new Percentage_Command();
}

Parenthesis_Command* Stack_Expr_Command_Factory::create_parenthesis_command (void)
{
           
    //Parenthesis_Command* cmd=new Parenthesis_Command();
    return new Parenthesis_Command();

    
}

/*Parenthesis_Command* Stack_Expr_Command_Factory::create_left_parenthesis_command (void)
{
    
    Parenthesis_Command* cmd=new Parenthesis_Command();
    return cmd;
    
    
}*/