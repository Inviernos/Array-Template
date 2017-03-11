#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          
#include <stdexcept>


class Array
{
public:

  
  Array (void);
  
  Array (size_t length);
  
  Array (size_t length, char fill);
  
  Array (const Array & arr);
  
  ~Array (void);
  
  const Array & operator = (const Array & rhs);
  
  size_t size (void) const;
  
  size_t max_size (void) const;
  
  char & operator [] (size_t index);
  
  const char & operator [] (size_t index) const;

  char get (size_t index) const;

  void set (size_t index, char value);

  void resize (size_t new_size);
  
  int find (char ch) const;
  
  int find (char ch, size_t start) const;

  bool operator == (const Array & rhs) const; 
  
  bool operator != (const Array & rhs) const;

  void fill (char ch);

private:
  char * data_;
  size_t cur_size_;
  size_t max_size_;
};

#include "Array.inl"

#endif  
