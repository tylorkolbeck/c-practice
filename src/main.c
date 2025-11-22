#include "memory_helpers.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
  int numbers[5] = {1, 2, 3, 4, 5};

  for (int i = 0; i < 5; i++) {
    printf("Number: %d\n", numbers[i]);
  }
  return 0;
}
