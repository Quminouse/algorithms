#include <stdio.h>

bool test_assert(bool expression, const char *message) {
  if (!expression) {
    printf("%s\n", message);
  }
  return expression;
}

bool test_assert(bool expression, const char *fail_message,
                 const char *pass_message) {
  if (!expression) {
    printf("%s\n", fail_message);
    return expression;
  }
  printf("%s\n", pass_message);
  return expression;
}
