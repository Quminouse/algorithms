#include "hashmap.cpp"

int main() {
  auto hashmap = HashMap<const char *, int>();
  printf("%d ", hashmap.hash("AB"));
  printf("%d ", hashmap.hash("AC"));
}

void array_example() {
  // Make array
  auto vector = Vector<int>(10);
  vector.insert(5, 9);
  int list[] = {1, 1, 1, 1, 1, 1};
  vector.insert(list, sizeof(list) / sizeof(list[0]), 0);

  // Sub array
  auto sub_array = vector.get(0, 5).unwrap();
  auto sub_vector = Vector<int>(5);
  sub_vector.insert(sub_array, 5, 0);

  // Print arrays
  sub_vector.print();
  vector.print();
}
