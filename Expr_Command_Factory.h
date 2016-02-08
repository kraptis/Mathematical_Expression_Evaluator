//
//  Expr_Command_Factory.h
//  
//
//  Created by Dinos Raptis on 3/6/15.
//
//

#ifndef ____Expr_Command_Factory__
#define ____Expr_Command_Factory__

#include <iostream>
//#include "Expr_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Number_Command.h"
#include "Multiply_Command.h"
#include "Devide_Command.h"
#include "Parenthesis_Command.h"
#include "Percentage_Command.h"




class Expr_Command_Factory
{
    
    public:
    
        Expr_Command_Factory (void);
    
        virtual ~Expr_Command_Factory (void)=0;
    
        virtual Number_Command * create_number_command (int num)=0;
    
        virtual Add_Command * create_add_command (void) = 0;
    
        virtual Subtract_Command * create_subtract_command (void) = 0;
    
        virtual Multiply_Command * create_multiply_command (void) = 0;
    
        virtual Devide_Command * create_devide_command (void) = 0;
    
        virtual Percentage_Command * create_percentage_command (void) = 0;
    
        virtual Parenthesis_Command * create_parenthesis_command (void) = 0;
    
        //virtual Parenthesis_Command * create_right_parenthesis_command (void) = 0;
   
    
    private:
        // prevent the following operations
    
        Expr_Command_Factory (const Expr_Command_Factory &);
    
        const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
    
};



#endif /* defined(____Expr_Command_Factory__) */