//
//  Calculator_Flyweight.cpp
//  
//
//  Created by Dinos Raptis on 3/6/15.
//
//

#include "Calculator_Flyweight.h"
#include <stdlib.h>
//#include "Stack.h"
//#include "Expr_Command.h"

Calculator_Flyweight::Calculator_Flyweight()
{
}

Calculator_Flyweight::~Calculator_Flyweight()
{
}

bool Calculator_Flyweight::infix_to_postfix(const std::string & infix, Flyweight_Expr_Command_Factory & factory, Array<Expr_Command *>& postfix)
{
	std::istringstream input(infix);
	std::string token;
    
	int num=0;
	Expr_Command * cmd = 0;
    
	Stack <Expr_Command * > temp;
	size_t i=0;
    
    //variables for checking if infix expression is correct
	//numbers must be always +1 than operators(except parenthesis)
	//parentheses balnced is checked in other method
    int countnum=0;
    int countops=0;
   
    
    
	while(!input.eof())
	{
		input >> token;
        
               
        
            
			if(token== "(")
			{
				cmd = factory.create_parenthesis_command();
				temp.push(cmd);
			}
			else if(token == "+")
			{
                if(countnum==countops+1)
                {
                    countops++;
                    cmd=factory.create_add_command();
                    Check_Priority(temp,postfix,cmd,i);
                }
                else break;
			}
			else if(token == "-")
			{
                if(countnum==countops+1)
                {
                    countops++;
                    cmd= factory.create_subtract_command();
                    Check_Priority(temp,postfix,cmd,i);
                }
                else break;
				
			}
			else if(token == "*")
			{
                if(countnum==countops+1)
                {
                    countops++;

                    cmd= factory.create_multiply_command();
                    Check_Priority(temp,postfix,cmd,i);
                }
                else break;
			}
			else if(token == "/")
			{
                if(countnum==countops+1)
                {
                    countops++;
                    cmd= factory.create_devide_command();
                    Check_Priority(temp,postfix,cmd,i);
                }
                else break;
                
			}
			else if(token == "%")
			{
                if(countnum==countops+1)
                {
                    countops++;
                    cmd= factory.create_percentage_command();
                    Check_Priority(temp,postfix,cmd,i);
                }
                else break;
                
			}
			else if(token == ")")
			{
                
                Expr_Command * tempcmd = temp.top();
                
				while(tempcmd->priority()!=0 && temp.size()!=0)
				{
					postfix.resize(postfix.cur_size_+1);
					postfix[i]= tempcmd;
					i++;
					temp.pop();
					
					if(temp.size()!=0)
					{
						tempcmd=temp.top();
					}
                    
				}
				temp.pop();
				
			}
			else if(!(atoi(token.c_str())==0 & token[0]!='0'))
			{
			     std::istringstream token_num(token);
                 token_num >> num;
                 countnum++;
			     cmd= factory.create_number_command(num);
                postfix.resize(postfix.cur_size_+1);
				postfix[i]=cmd;
			     
                
			     i++;
                
			}
            else{
                //std::cout <<"\nWrong expression " ;
                return false;

            }
            
            
		
        
	}
	
	
	while(temp.size()!=0)
	{
        postfix.resize(postfix.cur_size_+1);
        postfix[i]=temp.top();
            
	     temp.pop();
	     i++;
		
	}
   
    if(countnum==countops+1)
        return true;
    else
        return false;
}


void Calculator_Flyweight::Check_Priority(Stack<Expr_Command *>& temp,Array<Expr_Command *>& postfix, Expr_Command * cmd,size_t &i)
{
	if(temp.size()==0)
	{
		temp.push(cmd);
		return;
	}
	else
	{
		Expr_Command * tempcmd= temp.top();
        
		//if it is an open parenthesis
   		if(cmd->priority() == 0)
		{
			temp.push(cmd);
			return;
		}
		if(tempcmd->priority() < cmd->priority())
		{
			temp.push(cmd);
		}
		else
		{
			while((cmd->priority()<=tempcmd->priority()) && (temp.size()!=0))
			{
                postfix.resize(postfix.cur_size_+1);
				
				postfix[i]=tempcmd;
                //postfix.set(i,tempcmd);
				i++;
				temp.pop();
				if(temp.size()!=0)
				{
					tempcmd= temp.top();
				}
				
			}
			temp.push(cmd);
			
		}
		
	}
}

int Calculator_Flyweight::calculate(Array_Iterator<Expr_Command *> & arr_iter,Array <Expr_Command *> pos)
{
	Stack <int> s;
    int result;
    
    
	for(arr_iter; ! arr_iter.is_done(); arr_iter.advance())
	{
        //std::cout<<s.size();
		if( !(*arr_iter)->execute(s))
		{
			return false;
        }
        
        
		if((*arr_iter)->priority()==-1)
		{
			delete *arr_iter;
		}
        
	}
   
   
	result = s.top();
	s.pop();
    
	return  result;
    
}

void Calculator_Flyweight::run(const std::string & infix)
{
   
    int result;
    bool check=false;
    
    Flyweight_Expr_Command_Factory factory;
    Array <Expr_Command *> postfix;
    
    check=infix_to_postfix (infix, factory,postfix);
    if(check==false){
        std::cout <<"\nWrong expression " ;
        return;
    }
    //std::cout << postfix.size();
    Array_Iterator<Expr_Command *> arr_iter(postfix);

    result=calculate(arr_iter,postfix);
    std::cout <<"\nResult : " <<result;
}

bool Calculator_Flyweight::ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')')
        return true;
	else
        return false;
}

bool Calculator_Flyweight::AreParanthesesBalanced(std::string exp)
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






