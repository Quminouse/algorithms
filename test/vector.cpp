#include "../vector.cpp"
#include "test_assert.cpp"

#define TEST_COUNT 5

bool test_insert_get(int value, unsigned int index);
bool test_push_pop(int value);
bool test_fill(int value);
bool test_clear();
bool test_resize(unsigned int capacity);

bool test_vector() {
  unsigned int pass_count = 0;
  printf("\n");
  printf("VECTOR TEST\n");
  printf("------------------------------\n");
  pass_count += test_insert_get(20, 5);
  pass_count += test_push_pop(5);
  pass_count += test_fill(5);
  pass_count += test_clear();
  pass_count += test_resize(20);
  printf("------------------------------\n");
  printf("TESTS PASSED: %d/%d\n", pass_count, TEST_COUNT);

  return pass_count == TEST_COUNT;
}

// Insert and retrive element from a vector
bool test_insert_get(int value, unsigned int index) {
  auto vector = Vector<int>();
  vector.insert(value, index);
  return test_assert(vector.get(index).unwrap() == value,
                     "TEST FAILED: VECTOR/INSERT_GET",
                     "TEST PASSED: VECTOR/INSERT_GET");
}

bool test_push_pop(int value) {
  auto vector = Vector<int>();
  vector.push(value);
  return test_assert(vector.pop() == value, "TEST FAILED: VECTOR/PUSH_POP",
                     "TEST PASSED: VECTOR/PUSH_POP");
}

bool test_fill(int value) {
  auto vector = Vector<int>();
  bool pass = 1;
  vector.fill(value);
  for (unsigned int i = 0; i < vector.get_capacity(); ++i) {
    if (vector.get(i).unwrap() != value) {
      pass = 0;
      break;
    }
  }
  return test_assert(pass, "TEST FAILED: VECTOR/FILL",
                     "TEST PASSED: VECTOR/FILL");
}

bool test_clear() {
  auto vector = Vector<int>();
  bool pass = 1;
  vector.fill(5);
  vector.clear();
  for (unsigned int i = 0; i < vector.get_capacity(); ++i) {
    if (vector.get(i).unwrap() != 0) {
      pass = 0;
      break;
    }
  }
  return test_assert(pass, "TEST FAILED: VECTOR/CLEAR",
                     "TEST PASSED: VECTOR/CLEAR");
}

bool test_resize(unsigned int capacity) {
  auto vector = Vector<int>();
  vector.resize(capacity);
  return test_assert(vector.get_capacity() == capacity,
                     "TEST FAILED: VECTOR/RESIZE",
                     "TEST PASSED: VECTOR/RESIZE");
}
