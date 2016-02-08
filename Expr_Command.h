//
//  Expr_Command.h
//  
//
//  Created by Dinos Raptis on 3/6/15.
//
//

#ifndef ____Expr_Command__
#define ____Expr_Command__

#include <iostream>
#include "Stack.h"


class Expr_Command {
public:
    Expr_Command(void);
    
    virtual ~Expr_Command(void)=0;
    virtual int priority()=0;
    virtual bool execute (Stack<int> &s)=0;
    
    
    
    
    
private:
    //int priority;
};

/*class Number_Command : public Expr_Command {
public:
    virtual bool execute (int n1);
private:
    //int n2;
    int priority;
    
};

class Add_Command : public Expr_Command {
public:
    virtual bool execute (int n1,int n2);
private:
    int priority;
};
class Subtract_Command : public Expr_Command {
    public:
    virtual bool execute (int n1,int n2);
private:
    int priority;
};

class Multiply_Command : public Expr_Command {
    public:
    virtual bool execute (int n1,int n2);
private:
    int priority;
};
class Devide_Command : public Expr_Command {
    public:
    virtual bool execute (int n1,int n2);
private:
    int priority;
};
class Percentage_Command : public Expr_Command {
    public:
    virtual bool execute (int n1,int n2);
private:
    
    int priority;
};

class Parenthesis_Command : public Expr_Command {
public:
    virtual bool execute ();
private:
    int priority;
};*/


#endif /* defined(____Expr_Command__) */
