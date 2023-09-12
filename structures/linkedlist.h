#pragma once
#include "../result/result.h"
#include "vector.h"

enum LinkedListError {
  LINKED_LIST_GET_ERROR = 1,
};

template <typename T> class LinkedList {
private:
  Vector<T> data;
  LinkedList<T> *next;

public:
  LinkedList<T>(LinkedList<T> *_next, Vector<T> data);
  ~LinkedList<T>();

  Result<T, LinkedListError> get(T value, unsigned int index);
};
