#include "vector.cpp"

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
