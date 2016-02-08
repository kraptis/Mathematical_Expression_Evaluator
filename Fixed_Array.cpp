//
//  Fixed_Array.cpp
//  composition_xcode
//
//  Created by Dinos Raptis on 2/14/15.
//  Copyright (c) 2015 Dinos Raptis. All rights reserved.
//

// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
:Array<T>()
// Konstantinos, you need to call the appropriate constructor on
// the base class. Right now, you fixed array will not function
// correctly.
{
    
    
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
:Array<T>(arr)
// Konstantinos, you need to call the appropriate constructor on
// the base class. Right now, you fixed array will not function
// correctly.
{
    //data_=arr.data_;
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
:Array<T>(arr)
// Konstantinos, you need to call the appropriate constructor on
// the base class. Right now, you fixed array will not function
// correctly.
{
    
   
    
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
:Array<T>(N,fill)
// Konstantinos, you need to call the appropriate constructor on
// the base class. Right now, you fixed array will not function
// correctly.
{
    
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
// Konstantinos, you need to call the appropriate constructor on
// the base class. Right now, you fixed array will not function
// correctly.
{
   
    
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if (this == &rhs) {
        return *this;
    }
    else {
        if (this->max_size() != rhs.max_size()){
            return *this;
        }
        for (int i = 0; i < this->max_size(); i++)
            this->set(i, rhs [i]);
        
    }
    
    return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
    if (this == &rhs) {
        return *this;
    }
    else {
        if (this->max_size() != rhs.max_size()){
            return *this;
        }
        for (int i = 0; i < this->max_size(); i++)
            this->set(i, rhs [i]);
        
    }
    
    return *this;
    
}
