template <typename T>
inline
size_t Queue <T>::size (void) const
{
	//return the size of the queue, if front =-1 then is empty, 
	if(front_==-1)
		return 0;
	else
    	return (abs(front_-rear_)+1);
}




//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    return (front_ == -1);
}
