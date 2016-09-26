// ----------------------------------------------------------------------------
// Vector.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef VECTOR_H
#define VECTOR_H

#ifdef ARDUINO
    #if ARDUINO >= 100
        #include <Arduino.h>
    #else
        #include <WProgram.h>
    #endif
#else
    #include <cstddef>
#endif


template <typename T>
class Vector
{
public:
  Vector();
  template <size_t MAX_SIZE>
  Vector(T (&values)[MAX_SIZE], size_t size=0);
  template <size_t MAX_SIZE>
  void setStorage(T (&values)[MAX_SIZE], size_t size=0);
  T & operator[](const size_t i);
  T & at(const size_t i);
  T & front();
  T & back();
  void clear();
  template <typename U>
  void fill(const U & value);
  template <typename U, size_t N>
  void fill(const U (&values)[N]);
  template <typename U>
  void fill(const Vector<U> & values);
  template <typename U>
  void assign(const size_t n, const U & value);
  template <typename U, size_t N>
  void assign(const size_t n, const U (&values)[N]);
  template <typename U>
  void assign(const size_t n, const Vector<U> & values);
  void push_back(const T & value);
  void pop_back();
  size_t size();
  size_t max_size();
  bool empty();
  bool full();
  T * data();

private:
  T * values_;
  size_t max_size_;
  size_t size_;
};

template <typename T>
inline Print & operator <<(Print & stream, const Vector<T> & vector)
{
  stream.print("[");
  for (int i=0; i<vector.size(); i++)
  {
    if (i != 0)
    {
      stream.print(",");
    }
    stream.print(vector[i]);
  }
  stream.print("]");
  return stream;
}

#include "VectorDefinitions.h"

#endif
