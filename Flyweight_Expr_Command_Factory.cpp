//
//  Flyweight_Expr_Command_Factory.cpp
//  
//
//  Created by Dinos Raptis on 4/19/15.
//
//

#include "Flyweight_Expr_Command_Factory.h"

Flyweight_Expr_Command_Factory::Flyweight_Expr_Command_Factory()
{
	//stateless objects are created  and are shared
	this->add_ = new Add_Command();
	this->sub_ = new Subtract_Command();
	this->mul_ = new Multiply_Command();
	this->per_ = new Percentage_Command();
	this->dev_ = new Devide_Command();
	this->parenthesis_ = new Parenthesis_Command();
}

Flyweight_Expr_Command_Factory::~Flyweight_Expr_Command_Factory(void)
{
	
	//deallocation takes place when destructor of Flyweight_Expr_Command_Factory is called
	delete this->add_;
	delete this->sub_;
	delete this->mul_;
	delete this->dev_;
	delete this->per_;
	delete this->parenthesis_;
    
}


Number_Command * Flyweight_Expr_Command_Factory:: create_number_command(int num)
{
	
	return new Number_Command(num);
}


Add_Command * Flyweight_Expr_Command_Factory:: create_add_command(void)
{
	return this->add_;
}


Subtract_Command * Flyweight_Expr_Command_Factory:: create_subtract_command(void)
{
	return this->sub_;
}


Multiply_Command * Flyweight_Expr_Command_Factory:: create_multiply_command(void)
{
	return this->mul_;
}


Devide_Command * Flyweight_Expr_Command_Factory:: create_devide_command(void)
{
	return this->dev_;
}



Percentage_Command * Flyweight_Expr_Command_Factory:: create_percentage_command(void)
{
	return this->per_;
}


Parenthesis_Command * Flyweight_Expr_Command_Factory::create_parenthesis_command(void)
{
	return this->parenthesis_;
}
