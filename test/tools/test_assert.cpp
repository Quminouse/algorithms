#pragma once

#include <stdio.h>

bool test_assert(bool expression, const char *message) {
  if (!expression) {
    printf("%s%s\n", "TEST FAILED: ", message);
    return expression;
  }
  printf("%s%s\n", " TEST PASSED: ", message);
  return expression;
}

