//
//  Queue.h
//  composition_xcode
//
//  Created by Dinos Raptis on 2/14/15.
//  Copyright (c) 2015 Dinos Raptis. All rights reserved.
//

#ifndef ____Queue__
#define ____Queue__

#include <exception>
#include <cmath>
#include <stdlib.h>

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
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
    Queue (void);
    
    /// Copy constructor.
    Queue (const Queue & s);
    
    /// Destructor.
    ~Queue (void);
    
    /**
     * Assignment operator
     *
     * @param[in]      rhs           Right-hand side of operator
     * @return         Reference to self
     */
    const Queue & operator = (const Queue & rhs);
    
    /**
     * add a new \a element at the end of the list.
     *
     *
     * @param[in]      element       Element to add to the list
     */
    void enqueue (T element);
    
    /**
     * Remove the first element from the list.
     *
     * @exception      empty_exception    The stack is empty.
     */
    void dequeue (void);
    
    
    /**
     * Test if the queue is empty
     *
     * @retval         true          The queue is empty
     * @retval         false         The queue is not empty
     */
    bool is_empty (void) const;
    
    /**
     * Number of element on the queue.
     *
     * @return         Size of the queue.
     */
    size_t size (void) const;
    
    /// Remove all elements from the queue.
    void clear (void);
    
private:
    // Konstantinos, there is no need allocate the array on the heap.
    // It is OK to allocate it on the stack.
    
    // add member variable here
    //Array <T>  *elements_;
    
	int front_; //the front element of the circular queue
    int rear_; // the rear element of the circular queue
    
    // Konstantinos, there is no need to allocate an exception object.
    // This is just taking up unnecessary space/memory in the class.
	//empty_exception error;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_Queue_H_
