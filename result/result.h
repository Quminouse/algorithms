#pragma once

template <typename T, typename E> class Result {
private:
  T value;
  E error;
  bool result;
  Result(T val);
  Result(E err);

public:
  ~Result();

  static Result Ok(T value);
  static Result Err(E error);

  T unwrap();

  bool is_ok();
  bool is_err();
};
