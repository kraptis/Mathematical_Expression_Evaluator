
#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_SIZE 0

//using namespace std;
//
// Array
//
template <typename T>
Array <T>::Array (void)
: data_(0),
cur_size_(0),
max_size_(0)
{
	
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:data_(new T[length]),
cur_size_(0),
max_size_(length)
{
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:	data_(new T[length]),
	cur_size_(length),
	max_size_(length)
{

	this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
:	data_(new T[array.cur_size_]),
	cur_size_(array.cur_size_),
	max_size_(array.max_size_)
{
	std::copy(array.data_,array.data_+array.cur_size_,this->data_);	
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	if(this->data_!=0)
	{
		delete [] this->data_;
		this->data_=0;
	}
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	//***checking for self assignment
	if(this != &rhs) 
	{
		delete [] this->data_;
		//***creating a temporary array and copying the contents
		Array temporary(rhs);
		this->data_= new T[temporary.cur_size_];

		this->cur_size_=temporary.cur_size_;
		this->max_size_=temporary.max_size_;
		
		std::copy(temporary.data_,temporary.data_+temporary.cur_size_,this->data_);
		
	}
	return *this;
  
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if(index < this->size())
	{
		return this->data_[index];
	}
	else
	{
		throw std::out_of_range("Index is out of range");
	}
	

}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	if(index < this->size())
	{
		return this->data_[index];
	}
	else
	{
		throw std::out_of_range("Index is out of range");
	}
	
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{

	if(index < this->size())
	{
		return this->data_[index];	
	}
	else
	{
		throw std::out_of_range("Index is out of range");
	}
	
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	if(index < this->size())
	{
		this->data_[index]=value;
	}
	else
	{
		throw std::out_of_range("Invalid Index Value");
	}
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	
	if(new_size > this->max_size())
	{
		T *n_data = new T[new_size];
		
		//*** Preserving the original contents
		for(size_t i = 0 ; i < this->cur_size_ ; i++)
		{
			n_data[i]= this->data_[i];
		}
		delete [] this->data_;

		this->cur_size_=new_size;
		this->max_size_=new_size;
				
		this->data_=n_data;
		//delete [] n_data;

	}
	//*** New size less than the current size Truncate the array
	else if(new_size < this->size()) 
	{
		//*** Truncating the array
		this->cur_size_=new_size;
		

	}

}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
	for(size_t i = 0 ; i < this->size() ; i++)
	{
		if(this->data_[i] == value)
		{
			return (int)i;
		
		}
	}
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
	if(start < this->size())
	{
		for(size_t j = start ; j < this->size() ; j++)
		{
			if(this->data_[j] == val)
			{
				return (int)j;
			}
		}
		return -1; //*** Character Not Found return -1
	}
	else
	{
		throw std::out_of_range("Index is out of range");
	}
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if(this->size() != rhs.size())
	{
		//***They are not equal, return false.
		return false;
	}
	else
	{
		//***Check for their contents
		for(size_t i=0;i<this->size();i++)
		{
			if(this->data_[i]!=rhs.data_[i])
			{
				//***If atleast one of the value does not match return false
				return false;
			}
		}
		//***All the values match return true
		return true;
	}
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	if(this->operator==(rhs))
	{
		//***If both arrays are equal return False else return True
		return false;
	}
	else
	{
		return true;
	}
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	for(size_t i=0 ; i < this->size() ; i++)
	{
		this->data_[i] = value;
	}
}
