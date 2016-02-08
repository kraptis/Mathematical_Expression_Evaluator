//
//  main.cpp
//  composition_xcode
//
//  Created by Dinos Raptis on 2/14/15.
//  Copyright (c) 2015 Dinos Raptis. All rights reserved.
//

#include <iostream>
#include "Array.h"
//#include "Fixed_Array.h"
//#include "Stack.h"
//#include "Queue.h"
#include "Calculator_Visito_v2.h"
#include "Calculator_Postfix.h"
#include "Calculator_Flyweight.h"
#include "Expr_Command_Factory.h"
#include "Expr_Command.h"
#include "Flyweight_Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"
//#include "Array_Iterator.h"
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <time.h>




int main(int argc, const char * argv[])
{
    
    
    int b=0;//0 read for text file the expressions, 1 the user give the expression and choose the evaluation method
    
    
    std::string method;
    
    if(b==0){
    
    std::ifstream Exprfile;
    
	Exprfile.open("expressions.txt");
    
    clock_t t1;
	t1 = clock();
    
    while(!Exprfile.eof()){
        std::string infix;
        getline(Exprfile, infix);
        if(infix=="QUIT")
            break;
        std::cout << "     \n"<<infix;
        Calculator_Flyweight c1;
        if(c1.AreParanthesesBalanced(infix)){
            c1.run(infix);
        }
        else
            std::cout<<"Not Balanced parenthesis\n";
    
        std::cout << "     \n";
    }
    
    t1 =(clock() - t1)/(CLOCKS_PER_SEC/1000);
    
    Exprfile.close();
    
    Exprfile.open("expressions.txt");
    
    clock_t t2;
	t2 = clock();
    
    while(!Exprfile.eof()){
        std::string infix;
        getline(Exprfile, infix);
        if(infix=="QUIT")
            break;
        std::cout << "     \n"<<infix;
        Calculator_Postfix c2;
        if(c2.AreParanthesesBalanced(infix)){
            c2.run(infix);
        }
        else
            std::cout<<"Not Balanced parenthesis\n";
    
        std::cout << "  \n";
    }
    
    t2 =(clock() - t2)/(CLOCKS_PER_SEC/1000);
    
    Exprfile.close();
    
    Exprfile.open("expressions.txt");
    
    clock_t t3;
	t3 = clock();
    
    while(!Exprfile.eof()){
        std::string infix;
        getline(Exprfile, infix);
        if(infix=="QUIT")
            break;
        std::cout << "     \n"<<infix;
        Calculator_Visito_v2 c3;
        if(c3.AreParanthesesBalanced(infix)){
            c3.evaluate_expr(infix);
        }
        else
            std::cout<<"Not Balanced parenthesis\n";
    
        std::cout << "  \n";
    }
    
    t3 =(clock() - t3)/(CLOCKS_PER_SEC/1000);
    
    Exprfile.close();
    
    std::cout<<"\n Time Flyweight version: "<<t1<<" millisecs";
    std::cout<<"\n Time Postfix version: "<<t2<<" millisecs";
    std::cout<<"\n Time Tree version: "<<t3<<" millisecs";
    
    }
    
    while(b==1){
        std::cout<<"Give the method: 0 for postfix, 1 for flyweight, 2 for visitor \n";
        std::getline (std::cin,method);
        std::string infix;
        if(method=="0"|| method=="1"||method=="2"){
            //check=1;
            std::cout<<"Give the expression or QUIT\n";
            std::getline (std::cin,infix);
        }
        if(infix!="QUIT")
        {
            if(method=="1"){
                Calculator_Flyweight c;
                if(c.AreParanthesesBalanced(infix)){
                    c.run(infix);
                }
                else
                    std::cout<<"Not Balanced parenthesis\n";
                
                std::cout << "  \n";

            }
            else if(method=="0"){
                Calculator_Postfix c;
                if(c.AreParanthesesBalanced(infix)){
                    c.run(infix);
                }
                else
                    std::cout<<"Not Balanced parenthesis\n";
                
                std::cout << "  \n";

            }
            else if(method=="2"){
                Calculator_Visito_v2 c;
                if(c.AreParanthesesBalanced(infix)){
                    c.evaluate_expr(infix);
                }
                else
                    std::cout<<"Not Balanced parenthesis\n";
                
                std::cout << "  \n";

            }
            else
                std::cout<<"Wrong input\n";

            
        }
        else
            b=0;
    }
        
    return 0;
}

