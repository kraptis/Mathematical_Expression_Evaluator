//
//  Calculator_Flyweight_Flyweight.h
//  
//
//  Created by Dinos Raptis on 3/6/15.
//
//

#ifndef ____Calculator_Flyweight__
#define ____Calculator_Flyweight__

#include <iostream>
//#include "Expr_Command_Factory.h"
#include "Flyweight_Expr_Command_Factory.h"
#include "Expr_Command.h"
#include "Array.h"
#include "Stack.h"
#include "Array_Iterator.h"
#include <sstream>
#include <cctype>




class Calculator_Flyweight{
    
    public:
    
    Calculator_Flyweight(void);
    virtual ~Calculator_Flyweight(void);
    
        //it converts an infix expression to a postfix expression
    bool infix_to_postfix (const std::string & infix, Flyweight_Expr_Command_Factory & factory,Array <Expr_Command *> & postfix);
        
        // check and swap the priorities of the operators
    void Check_Priority(Stack<Expr_Command *>& temp,Array<Expr_Command *>& postfix, Expr_Command * cmd,size_t &i);
    
        
    int calculate(Array_Iterator<Expr_Command *> & arr_iter,Array <Expr_Command *> pos);
    
        
    void run(const std::string & infix);
    
    // checking if parentheses are balanced
    bool ArePair(char opening,char closing);
    // checking if parentheses are balanced
    bool AreParanthesesBalanced(std::string exp);
    
    

};



#endif /* defined(____Calculator_Flyweight__) */
