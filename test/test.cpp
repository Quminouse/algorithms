#include "tests/hashmap.cpp"
#include "tests/result.cpp"
#include "tests/vector.cpp"

#include <stdio.h>

int main() {
  unsigned int fail_count = 0;
  fail_count += test_result();
  fail_count += test_vector();
  fail_count += test_hashmap();
  printf("------------------------------\n");
  printf("------------------------------\n");
  printf("TOTAL TESTS FAILED: %d", fail_count);
}
