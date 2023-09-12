#pragma once
#include "../result/result.h"
#include "vector.h"
#include "linkedlist.h"

enum HashMapError {
  GET_ERROR = 1,
};

template <typename K, typename V> class HashMap {
private:
  Vector<LinkedList<V>> data;
  unsigned int capacity;

public:
  HashMap();
  ~HashMap();

  static unsigned int hash_function(K value);
  static unsigned int hash_function(K *value);

  void insert(K key, V value);
  void insert(K *key, V value);

  Result<V, HashMapError> get(K key);
  Result<V, HashMapError> get(K *key);
};
