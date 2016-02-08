//
//  Calculator_Visito_v2_Visito_v2.h
//  
//
//  Created by Dinos Raptis on 3/27/15.
//
//

#ifndef ____Calculator_Visito_v2__
#define ____Calculator_Visito_v2__

#include <iostream>
#include "Expr_Tree_Builder.h"
//#include "Expr_Builder.h"

//#include "Eval_Expr_Tree.h"
#include <sstream>



class Calculator_Visito_v2{
    
public:
    Calculator_Visito_v2(void);
    virtual ~Calculator_Visito_v2(void);
    
    
    bool parse_expr (const std::string & infix, Expr_Tree_Builder &b);
    
    bool evaluate_expr(const std::string &infix);
    
    // checking if parentheses are balanced
    bool ArePair(char opening,char closing);
    // checking if parentheses are balanced
    bool AreParanthesesBalanced(std::string exp);
    
};

#endif /* defined(____Calculator_Visito_v2__) */
