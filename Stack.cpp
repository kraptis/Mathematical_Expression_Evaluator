//
//  Stack.cpp
//  composition_xcode
//
//  Created by Dinos Raptis on 2/14/15.
//  Copyright (c) 2015 Dinos Raptis. All rights reserved.
//



//
// Stack
//
#include "Stack.h"
#define DEFAULT_SIZE 0

template <typename T>
Stack <T>:: Stack(void)
:elements_(DEFAULT_SIZE),top_(0)
{
   
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
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
