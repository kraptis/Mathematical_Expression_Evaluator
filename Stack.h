//
//  Stack.h
//  composition_xcode
//
//  Created by Dinos Raptis on 2/14/15.
//  Copyright (c) 2015 Dinos Raptis. All rights reserved.
//

//#ifndef __composition_xcode__Stack__
//#define __composition_xcode__Stack__

//#ifndef _Stack_H_
//#define _Stack_H_

//#include <iostream>

//#endif /* defined(__composition_xcode__Stack__) */

// -*- C++ -*-
// $Id: Stack.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_

#include <exception>
#include "Array.h"

/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */
template <typename T>
class Stack
{
public:
    /// Type definition of the type.
    typedef T type;
    
    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the stack is empty.
     */
    class empty_exception : public std::exception
    {
    public:
        /// Default constructor.
        empty_exception (void)
        : std::exception () { }
    };
   
    
    Array <T>  elements_;
    
    /// Default constructor.
    Stack (void);
    
    /// Copy constructor.
    Stack (const Stack & s);
    
    /// Destructor.
    ~Stack (void);
    
    /**
     * Assignment operator
     *
     * @param[in]      rhs           Right-hand side of operator
     * @return         Reference to self
     */
    const Stack & operator = (const Stack & rhs);
    
    /**
     * Push a new \a element onto the stack. The element is inserted
     * before all the other elements in the list.
     *
     * @param[in]      element       Element to add to the list
     */
    void push (T element);
    
    /**
     * Remove the top-most element from the stack.
     *
     * @exception      empty_exception    The stack is empty.
     */
    void pop (void);
    
    /**
     * Get the top-most element on the stack. If there are no element
     * on the stack, then the stack_is_empty exception is thrown.
     *
     * @return         Element on top of the stack.
     * @exception      empty_exception    The stack is empty
     */
    T top (void) const;
    
    /**
     * Test if the stack is empty
     *
     * @retval         true          The stack is empty
     * @retval         false         The stack is not empty
     */
    bool is_empty (void) const;
    
    /**
     * Number of element on the stack.
     *
     * @return         Size of the stack.
     */
    size_t size (void) const;
    
    /// Remove all elements from the stack.
    void clear (void);
    
private:
    // Konstantinos, there is no need allocate the array on the heap.
    // It is OK to allocate it on the stack.
    
    // add member variable here
   // Array <T>  *elements_;
	int top_; // the top element of the stack
    
    // Konstantinos, there is no need to allocate an exception object.
    // This is just taking up unnecessary space/memory in the class.
	//empty_exception error;
};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif  // !defined _CS507_STACK_H_