#pragma once

#include "../result/result.h"

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

  unsigned int get_capacity();

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
