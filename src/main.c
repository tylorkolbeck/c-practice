#include "coordinate/coordinate.h"
#include "memory_helpers.h"
#include "util/t_string.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
  char str1[50] = "Hello";
  char *str2 = " world";

  char newString[100];

  concat_strings(str1, str2);
  return 0;
}
