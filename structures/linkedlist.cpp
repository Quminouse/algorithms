#include "linkedlist.h"
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> *_next, Vector<T> _data) {
  next = _next;
  data = _data;
}

template <typename T> Result<T, LinkedListError> LinkedList<T>::get(T value, unsigned int index) {
  if (data.get(index) == (value)) {
    return Result<T, LinkedListError>::Ok(this);
  }
  if (next) {
    next->get(value);
  }
  return Result<T, LinkedListError>::Err(LinkedListError::LINKED_LIST_GET_ERROR);
}
