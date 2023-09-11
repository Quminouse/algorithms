#include "result.cpp"
#include <stdio.h>
#include <stdlib.h>

enum VectorError {
  NOT_IN_RANGE,
};

template <typename T> class Vector {
private:
  T *data;
  unsigned int capacity;
  unsigned int pointer;

public:
  Vector(unsigned int cap);
  Vector();
  ~Vector();

  void insert(T value, unsigned int index);
  void insert(T *values, unsigned int size, unsigned int index);
  Result<T, VectorError> get(unsigned int index);
  Result<T *, VectorError> get(unsigned int index, unsigned int size);

  void fill(T value);
  void clear();
  void resize(unsigned int size);

  void push(T value);
  T pop();

  void print();
};

template <typename T> Vector<T>::Vector(unsigned int cap) {
  capacity = cap;
  data = (T *)calloc(capacity, sizeof(T));
  pointer = 0;
}
template <typename T> Vector<T>::Vector() {
   capacity = 16;
   data = (T *)calloc(capacity, sizeof(T)); 
   pointer = 0;
}

template <typename T> Vector<T>::~Vector() { free(data); }

template <typename T> void Vector<T>::insert(T value, unsigned int index) {
  if (index < capacity) {
    data[index] = value;
  }
}

template <typename T>
void Vector<T>::insert(T *values, unsigned int size, unsigned int index) {
  for (unsigned int i = 0; i < size; ++i) {
    if (index + i >= capacity) {
      return;
    }
    data[index + i] = values[i];
  }
}

template <typename T>
Result<T, VectorError> Vector<T>::get(unsigned int index) {
  if (index >= capacity) {
    return Result<T, VectorError>::Err(VectorError::NOT_IN_RANGE);
  }
  return Result<T, VectorError>::Ok(data[index]);
}
template <typename T>
Result<T *, VectorError> Vector<T>::get(unsigned int index, unsigned int size) {
  if (index + size >= capacity) {
    return Result<T *, VectorError>::Err(VectorError::NOT_IN_RANGE);
  }
  return Result<T *, VectorError>::Ok(&data[index]);
}

template <typename T> void Vector<T>::fill(T value) {
  for (unsigned int i = 0; i < capacity; ++i) {
    data[i] = value;
  }
}
template <typename T> void Vector<T>::clear() {
  for (unsigned int i = 0; i < capacity; ++i) {
    data[i] = 0;
    pointer = 0;
  }
}
template <typename T> void Vector<T>::resize(unsigned int size) {
    capacity = size;
    realloc(data, capacity);
}

template <typename T> void Vector<T>::push(T value) {
  if (pointer + 1 >= capacity) {
    capacity *= 2;
    realloc(data, capacity);
  }
  data[pointer] = value;
  pointer++;
}
template <typename T> T Vector<T>::pop() {
  pointer--;
  return data[pointer + 1];
}

template <typename T> void Vector<T>::print() {
  printf("Capacity: %d\n", capacity);
  for (unsigned int i = 0; i < capacity; ++i) {
    printf("%d ", data[i]);
  }
  printf("\n");
}
