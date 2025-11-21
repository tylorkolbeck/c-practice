#include "memory_helpers.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void print_sizes() {
  printf("Size of char*: %zu bytes\n", sizeof(char *));
  printf("Size of double: %zu bytes\n", sizeof(double));
  printf("Size of size_t: %zu bytes\n", sizeof(size_t));
  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("Size of float: %zu bytes\n", sizeof(float));
  printf("Size of char: %zu bytes\n", sizeof(char));
  printf("Size of bool: %zu bytes\n", sizeof(bool));
  printf("Size of uintptr_t: %zu bytes\n", sizeof(uintptr_t));
}

void print_mem_addr(uintptr_t p) {
  printf("Decimal address: %" PRIuPTR "\n", p);
}
