//
//  Queue.cpp
//  composition_xcode
//
//  Created by Dinos Raptis on 2/14/15.
//  Copyright (c) 2015 Dinos Raptis. All rights reserved.
//

#include "Queue.h"
#define DEFAULT_SIZE 7



template <typename T>
Queue <T>:: Queue(void)
// Konstantinos, each member variable should be initialized on its own
// line. Repeat offense: -2 points.
:elements_(DEFAULT_SIZE),front_(-1),rear_(-1)
{
    
}


template <typename T>
Queue <T>::Queue (const Queue & queue)
// Konstantinos, each member variable should be initialized on its own
// line. Repeat offense: -2 points.
:elements_(abs(queue.front_-queue.rear_)+1),front_(queue.front_),rear_(queue.rear_)
{
    //copy all the elements to the new queue
    
    for(int i=0;i<abs(queue.front_-queue.rear_)+1;i++)
        elements_[i]=queue.elements_[i];
}

//
// ~Queue
//
template <typename T>
Queue<T>::~Queue (void)
{
    //the elements_ is allocated on the stack, no need for delete
    if(this->size()==0);
        elements_.resize(0);
    
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    // Konstantinos, there is no need to allocate a new array of
    // a different size and copy the elements over. That is the
    // purpose of the resize() method. Moreover, this is an ineffecient
    // design for a queue. You should be trying to use space as
    // effeciently as possible without have to resize() the queue for
    // each element inserted.
    
    
    //circular queue
    
    //check if is full, then resize
    if(((rear_+1) % elements_.max_size() == front_)){
        elements_.resize(elements_.max_size()+1);
    }
    
    // rear is the next element of the circle
    rear_ = (rear_ + 1) % elements_.max_size();
	elements_[rear_] = element;
    
    //when the queue is empty front is -1, so now is 0 
	if(front_ == -1)
		front_ = 0;
    
    
}

//
// dequeue
//
template <typename T>
void Queue <T>::dequeue (void)
{
    //if is empty throw exception
    if(front_<0)
        throw empty_exception();
    
    // dequeue the front element
	elements_[front_] = 0;
    
    //check if it is empty, else now front is the next item of the circlular queue
	if(front_==rear_){
		front_=-1;
		rear_=-1;
	}
	else
		front_=(front_+1) % elements_.max_size();
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    //assign the values
    elements_=rhs.elements_;
    front_=rhs.front_;
    rear_=rhs.rear_;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    //dequeue until is empty
    while(front_!=-1)
        dequeue();
}
