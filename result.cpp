#include <stdio.h>
#include <stdlib.h>

template <typename T, typename E> class Result {
private:
  T value;
  E error;
  bool result;
  Result(T val) {
    value = val;
    result = 1;
  }
  Result(E err) {
    error = err;
    result = 0;
  }

public:
  static Result Ok(T value) { return Result(value); }
  static Result Err(E error) { return Result(error); }

  ~Result() {}

  T unwrap() {
    if (result) {
      return value;
    }
    printf("ERROR: Result.unwrap() failed!");
    exit(error);
  }

  bool is_ok() { return result; }
  bool is_err() { return !result; }
};
