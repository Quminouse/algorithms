#include "hashmap.h"
#include <stdlib.h>

template <typename K, typename V> HashMap<K, V>::HashMap() {
  capacity = 16;
  data = Vector<LinkedList<V>>();
}

template <typename K, typename V> HashMap<K, V>::~HashMap() {}

template <typename K, typename V>
unsigned int HashMap<K, V>::hash_function(K value) {
  return (unsigned int)value;
};

template <typename K, typename V>
unsigned int HashMap<K, V>::hash_function(K *value) {
  unsigned int sum = 0;
  unsigned int i = 0;
  while (value[i]) {
    sum += (unsigned int)value[i] * (i + 1);
    i++;
  }
  return sum;
};

template <typename K, typename V> void HashMap<K, V>::insert(K key, V value) {
  unsigned int hash = hash_function(key);
  unsigned int index = hash % capacity;

  if (data.get(index).unwrap() == nullptr) {
    data.insert(LinkedList<V>(nullptr, Vector<V>({hash, value})), index);
    return;
  }
  if (data.get(index).unwrap().get(value).is_ok()) {
    data.get(index).unwrap().get(value).unwrap();
  }
  data.insert(LinkedList<V>(data.get(index).unwrap(), Vector<V>({hash, value})), index); 
}

template <typename K, typename V> void HashMap<K, V>::insert(K *key, V value) {
  unsigned int hash = hash_function(key);
}
