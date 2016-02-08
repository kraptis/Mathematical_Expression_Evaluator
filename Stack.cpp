//
//  Stack.cpp
//  composition_xcode
//
//  Created by Dinos Raptis on 2/14/15.
//  Copyright (c) 2015 Dinos Raptis. All rights reserved.
//

// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
#include "Stack.h"
#define DEFAULT_SIZE 0

template <typename T>
Stack <T>:: Stack(void)
// Konstantinos, each member variable should be initialized on its own
// line. Repeat offense: -2 points.
:elements_(DEFAULT_SIZE),top_(0)
{
   
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
// Konstantinos, each member variable should be initialized on its own
// line. Repeat offense: -2 points.
:elements_(stack.top_),top_(stack.top_)
{
    //copy all the elements
    
    for(int i=0;i<top_;i++)
        elements_[i]=stack.elements_[i];
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    //the elements_ is allocated on the stack, no need for delete
    if(this->size()==0);{
        elements_.resize(0);
    }
    
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    
    
    // Konstantinos, there is no need to allocate a new array each time
    // you want to add an element. Just use the resize() method.
    
    //check if it is full, then resize
        
    if(top_==elements_.max_size())
        elements_.resize(elements_.max_size()+1);
    
    top_++;
    //add the new element at the top of the stack
    //elements_[top_-1]=element;
    elements_.set(top_-1,element);
    
    
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    

    if(top_<0)
        throw empty_exception();
    
    // Konstantinos, do not set the old spae to NULL. This will result
    // in a compilation error if you use a type that does not support
    // type conversion with NULL.
    
    // Konstantinos, as stated in class many times, do not use NULL.
    // Instead, you 0 or nullptr (in case of C++11).
    //delete the top element of the stack
    //elements_[top_-1]==0;
    //elements_.set(top_-1,0);
    
    top_--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    //assign the values
    elements_=rhs.elements_;
    top_=rhs.top_;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    
    //pop until is empty
    while(top_>0)
        pop();
}
