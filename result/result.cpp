#include "result.h"
#include <stdio.h>
#include <stdlib.h>

template <typename T, typename E> Result<T, E>::Result(T val) {
  value = val;
  result = 1;
}
template <typename T, typename E> Result<T, E>::Result(E err) {
  error = err;
  result = 0;
}

template <typename T, typename E> Result<T, E> Result<T, E>::Ok(T value) {
  return Result(value);
}
template <typename T, typename E> Result<T, E> Result<T, E>::Err(E error) {
  return Result(error);
}

template <typename T, typename E> Result<T, E>::~Result() {}

template <typename T, typename E> T Result<T, E>::unwrap() {
  if (result) {
    return value;
  }
  printf("ERROR: Result.unwrap() failed!");
  exit(error);
}

template <typename T, typename E> bool Result<T, E>::is_ok() { return result; }
template <typename T, typename E> bool Result<T, E>::is_err() {
  return !result;
}
