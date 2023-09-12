#include "../../result/result.cpp"
#include "../tools/test_assert.cpp"

#define RESULT_TEST_COUNT 3

enum TestError {
  TEST = 1,
};

bool test_ok(int value);
bool test_err();
bool test_unwrap(int value);

unsigned int test_result() {
  unsigned int pass_count = 0;
  printf("\n");
  printf("RESULT TEST\n");
  printf("------------------------------\n");
  pass_count += test_ok(10);
  pass_count += test_err();
  pass_count += test_unwrap(10);
  printf("------------------------------\n");
  printf("TESTS PASSED: %d/%d\n", pass_count, RESULT_TEST_COUNT);

  return RESULT_TEST_COUNT - pass_count;
}

bool test_ok(int value) {
  auto result = Result<int, TestError>::Ok(value);
  return test_assert(result.is_ok() == true, "RESULT/OK");
}

bool test_err() {
  auto result = Result<int, TestError>::Err(TestError::TEST);
  return test_assert(result.is_err() == true, "RESULT/ERR");
}

bool test_unwrap(int value) {
  auto result = Result<int, TestError>::Ok(value);
  return test_assert(result.unwrap() == value, "RESULT/UNWRAP");
}
