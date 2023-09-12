#pragma once

#include "vector.h"
#include <stdlib.h>

template <typename K, typename V> class HashMap {
private:
  V *data;
  unsigned int capacity;

public:
  HashMap();
  ~HashMap();

  unsigned int hash(K value);
  unsigned int hash(K *value);
};

template <typename K, typename V> HashMap<K, V>::HashMap() {
  capacity = 16;
  data = (V *)calloc(capacity, sizeof(V));
}
template <typename K, typename V> HashMap<K, V>::~HashMap() { free(data); }

template <typename K, typename V> unsigned int HashMap<K, V>::hash(K value) {
  return (unsigned int)*value;
};
