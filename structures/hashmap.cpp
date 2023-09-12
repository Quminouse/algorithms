#include "hashmap.h"
#include <stdlib.h>

template <typename K, typename V> unsigned int HashMap<K, V>::hash(K *value) {
  unsigned int sum = 0;
  unsigned int i = 1;
  while (value) {
    sum += ((unsigned int)*value) * i;
    value++;
    i++;
  }
  return sum;
}
