//
//  Flyweight_Expr_Command_Factory.h
//  
//
//  Created by Dinos Raptis on 4/19/15.
//
//

#ifndef ____Flyweight_Expr_Command_Factory__
#define ____Flyweight_Expr_Command_Factory__

#include <iostream>

#include "Expr_Command_Factory.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Devide_Command.h"
#include "Percentage_Command.h"

class Flyweight_Expr_Command_Factory : public Expr_Command_Factory
{
public:
    
	Flyweight_Expr_Command_Factory();
    
    
	virtual ~Flyweight_Expr_Command_Factory(void);
    

     
	virtual Number_Command * create_number_command(int num);
    
    

	virtual Add_Command * create_add_command(void);
    

    
	virtual Subtract_Command * create_subtract_command(void);
    

	virtual Devide_Command * create_devide_command(void);
	

	virtual Multiply_Command * create_multiply_command(void);
    
    

	virtual Percentage_Command * create_percentage_command(void);
    
    

	virtual Parenthesis_Command * create_parenthesis_command(void);
    
    
private:
    
	Add_Command *add_;
	Subtract_Command *sub_;
	Multiply_Command *mul_;
	Devide_Command *dev_;
	Percentage_Command *per_;
	Parenthesis_Command *parenthesis_;
	
};

#endif /* defined(____Flyweight_Expr_Command_Factory__) */
