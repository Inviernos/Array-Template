#include "Array.h"

//Default constructor.
Array::Array (void): 
	data_ (new char[5]), 
	cur_size_ (0), 
	max_size_ (sizeof(char)*5)
{
	
}

//Initializing constructor.
Array::Array (size_t length): 
	data_ (new char[length]), 
	cur_size_ (0), 
	max_size_ (sizeof(char)*length)
{

}

// Initializing constructor.
Array::Array (size_t length, char fill): 
	data_ (new char[length]), 
	cur_size_ (length), 
	max_size_ (sizeof(char)*length)
{
   for(int i = 0;i<length;i++)
   {
	   data_[i] = fill;
   }
}

//Copy constructor
Array::Array (const Array & array):
	data_ (new char[array.max_size_]),
	cur_size_ (array.cur_size_),
	max_size_ (array.max_size_)
{

	for(unsigned int i = 0; i < max_size_; i++)
	{
		data_[i] = array.data_[i];
	}
}


//Destructor.
Array::~Array (void)
{
	delete [] data_;

	data_ = nullptr;
}

//Assignment operation
const Array & Array::operator = (const Array & rhs)
{
	if(this == &rhs)
	{
		return *this;
	}
	
	cur_size_ = rhs.cur_size_;

	max_size_ = rhs.max_size_;

	delete[] data_;

	data_ = new char[max_size_];

	for(unsigned int i = 0; i < max_size_; i++)
	{
		data_[i] = rhs.data_[i];
	}

	return *this;
	
}

//Get the character at the specified index. 
char & Array::operator [] (size_t index)
{
	try
	{
		return data_[index];
	}
	catch(std::out_of_range){}


	
}


  
  
//The returned character is not modifiable.
const char & Array::operator [] (size_t index) const
{
	try
	{
		return data_[index];
	}
	catch(std::out_of_range){}

}

//Get the character at the specified index.  
char Array::get (size_t index) const
{
	try
	{
		return data_[index];
	}
	catch(std::out_of_range){}
}

//Set the character at the specified index.
void Array::set (size_t index, char value)
{
	

	try
	{
		data_[index] = value;
	}
	catch(std::out_of_range){}
	
}


//Set a new size for the array. 
void Array::resize (size_t new_size)
{
	
	
	if(new_size > max_size_)
	{
		char *new_data_ = new char[max_size_];
		
		for(unsigned int i = 0;i < max_size_;i++)
		{
			new_data_[i] = data_[i];
		}

		delete [] data_;
		
		data_ = new char[new_size];

		for(unsigned int i = 0;i < max_size_;i++)
		{
			data_[i] = new_data_[i];
		}
		
		max_size_ = sizeof(char)*new_size;

		delete [] new_data_;
	}
	else
	{
		if(cur_size_ > new_size)
		{
			cur_size_ = new_size;
		}
	}

}

//Locate the specified character in the array.
int Array::find (char ch) const
{
	
	for(unsigned int i = 0; i < max_size_;i++)
	{
		if(data_[i] == ch)
		{
			return i;
		}
	}

	return -1;

}

//This version allows you to specify the start index of the search
int Array::find (char ch, size_t start) const
{
	bool searching = true;
	int index = 0;

	try
	{
		while(searching)
		{
			if(data_[start] == ch)
			{
				return start;
			}
			
			index++;
			
			if(start != max_size_)
			{
				start++;
			}
			else
			{
				start = 0;
			}

			if(index == max_size_)
			{
				searching = false;
			}
		}
	}
	catch(std::out_of_range){}

	return -1;
}
 
//Test the array for equality.
bool Array::operator == (const Array & rhs) const
{
	
	if(cur_size_ == rhs.cur_size_)
	{
		if(max_size_ == rhs.max_size_)
		{
			for(unsigned int i = 0;i<max_size_;i++)
			{
				if(data_[i] != rhs.data_[i])
				{
					return false;
				}
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Test the array for inequality.
bool Array::operator != (const Array & rhs) const
{
	return (!((*this) == rhs));
}

//Fill the contents of the array.
void Array::fill (char ch)
{
	
	for(int i = 0;i<max_size_;i++)
   {
	   data_[i] = ch;
   }

	cur_size_ = max_size_;
}
