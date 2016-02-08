//
//  Array_Iterator.h
//  
//
//  Created by Dinos Raptis on 3/9/15.
//
//

#ifndef ____Array_Iterator__
#define ____Array_Iterator__

//#include <iostream>
#include "Array.h"


template <typename T>
class Array_Iterator
{
public:
    
	typedef T type;
    
	Array_Iterator(Array<T> & arr);
    
	~Array_Iterator(void);
    
        //go to next element
	bool advance(void);
    
        // It examines all the elements of the array
	bool is_done(void);
	
	T * operator -> (void);
	T & operator * (void);
	
    
private:
    
	Array<T>  & a_;
    
	size_t curr_;
    
};

#include "Array_Iterator.cpp"

#endif /* defined(____Array_Iterator__) */
