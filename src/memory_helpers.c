#include "memory_helpers.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int *intPtr;
char *charPtr;
double *doublePtr;

void print_sizes() {
  printf("Size of int pointer: %zu bytes\n", sizeof(intPtr));
  printf("Size of char pointer: %zu bytes\n", sizeof(charPtr));
  printf("Size of double pointer: %zu bytes\n", sizeof(doublePtr));
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

bool is_mem_loc_eq(void *mem1, void *mem2) { return mem1 == mem2; }
