//
//  Calculator_Postfix.h
//  
//
//  Created by Dinos Raptis on 3/6/15.
//
//

#ifndef ____Calculator_Postfix__
#define ____Calculator_Postfix__

#include <iostream>
//#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"
#include "Expr_Command.h"
#include "Array.h"
#include "Stack.h"
#include "Array_Iterator.h"
#include <sstream>
#include <cctype>




class Calculator_Postfix{
    
    public:
    
        Calculator_Postfix(void);
    
	virtual ~Calculator_Postfix(void);
    
        //it converts an infix expression to a postfix expression
        bool infix_to_postfix (const std::string & infix, Stack_Expr_Command_Factory & factory,Array <Expr_Command *> & postfix);
        
        // swaps between  the operators according to their priority
        void Check_Priority(Stack<Expr_Command *>& temp,Array<Expr_Command *>& postfix, Expr_Command * cmd,size_t &i);
    
        // It calculates with the Iterator the result of the postfix, that's the final result
        int calculate(Array_Iterator<Expr_Command *> & arr_iter,Array <Expr_Command *> pos);
    
        // initialize how the programm is going to rub
        void run(const std::string & infix);
    
    // checking if parentheses are balanced
    bool ArePair(char opening,char closing);
    // checking if parentheses are balanced
    bool AreParanthesesBalanced(std::string exp);
    
    

};



#endif /* defined(____Calculator_Postfix__) */
