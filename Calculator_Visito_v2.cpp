//
//  Calculator_Visito_v2_Visito_v2.cpp
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#include "Calculator_Visito_v2.h"
#include "Eval_Expr_Tree.h"
#include "Expr_Tree_Builder.h"
#include "Stack.h"
#include <stdlib.h>


Calculator_Visito_v2::Calculator_Visito_v2()
{
    
}

Calculator_Visito_v2::~Calculator_Visito_v2()
{
    
}

bool Calculator_Visito_v2::parse_expr(const std::string & infix, Expr_Tree_Builder &b)
{
    
    std::istringstream input (infix);
	std::string token;
    
	int number=0;
	//variables for checking if infix expression is correct
	//numbers must be always +1 than operators(except parenthesis)
	//parentheses balnced is checked in other method
    int countnum=0;
    int countops=0;
    
    while (!input.eof ())
    {
        input >> token;
        if (token == "+")
        {
            
            if(countnum==countops+1)
            {
                countops++;
                b.build_addition_operand ();
            }
            else break;
        }
        else if (token == "-")
        {
            if(countnum==countops+1)
            {
                countops++;
                b.build_subtraction_operand ();
            }
        }
        else if (token == "*")
        {
            if(countnum==countops+1)
            {
                countops++;
                b.build_multiply_operand ();
            }
        }
        else if (token == "/")
        {
            if(countnum==countops+1)
            {
                countops++;
                b.build_divition_operand ();
            }
        }
        else if (token == "%")
        {
            if(countnum==countops+1)
            {
                countops++;
                b.build_percentage_operand ();
            }
        }
        else if (token == "(")
            b.build_open_parenthesis ();
        else if (token == ")"){
            b.build_close_parenthesis();
           
        }
        else if(!(atoi(token.c_str())==0 & token[0]!='0'))
        {
            std::istringstream token_num(token);
            token_num >> number;
            countnum++;
			b.build_number(number);
        }
        else{
            std::cout <<"\nWrong expression " ;
            return false;
        }
    }
    if(countnum==countops+1)
    {
        b.build_expression();
        return true;
    }
    else
    {
        std::cout<<"\n wrong expression!";
        return false;
    }
    
}

bool Calculator_Visito_v2::evaluate_expr(const std::string &infix)
{
    
    Expr_Tree_Builder builder;
	Eval_Expr_Tree eval;
    
	if(!parse_expr(infix,builder))
		return false;
    
	Expr_Node *expr;
    
        
	expr = builder.get_expression();
    
    
	if(0==expr)
		return false;
    
    
	expr->accept(eval);
    
	int result=eval.result();
    
	delete expr;
    std::cout<<"\n Result: "<<result;
    
    
	return true;
}

bool Calculator_Visito_v2::ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')')
        return true;
	else
        return false;
}

bool Calculator_Visito_v2::AreParanthesesBalanced(std::string exp)
{
	//check the parentheses balance
	
	Stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' )
			S.push(exp[i]);
		else if(exp[i] == ')')
		{
			if(S.size()==0 || !ArePair(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	if(S.size()==0)
        return true;
    else
        return false;
}



