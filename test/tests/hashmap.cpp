#include "../../structures/hashmap.cpp"
#include "../tools/test_assert.cpp"
#include <stdio.h>

#define HASHMAP_TEST_COUNT 2

bool test_hash(const char *key_1, const char *key_2);
bool test_insert_get(const char *key, int value);

unsigned int test_hashmap() {
  unsigned int pass_count = 0;
  printf("\n");
  printf("RESULT TEST\n");
  printf("------------------------------\n");
  test_hash("ABC", "CBA");
  test_insert_get("Key", 30);
  printf("------------------------------\n");
  printf("TESTS PASSED: %d/%d\n", pass_count, HASHMAP_TEST_COUNT);

  return HASHMAP_TEST_COUNT - pass_count;
}

bool test_hash(const char *key_1, const char *key_2) {
  auto hash_1 = HashMap<const char, int>::hash_function(key_1);
  auto hash_2 = HashMap<const char, int>::hash_function(key_2);

  return test_assert(hash_1 != hash_2, "HASHMAP/HASH_FUNCTION");
}

bool test_insert_get(const char *key, int value) {
  auto hashmap = HashMap<const char, int>();
  hashmap.insert(key, value);
  return test_assert(hashmap.get(key).unwrap() == value,
  "HASHMAP/INSERT_GET");
}
