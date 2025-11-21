#include "memory_helpers.h"
#include <stdbool.h>
#include <stdio.h>

void test_loop(void *arg) {
  long n = *(long *)arg;

  volatile long long sum = 0;
  for (long i = 0; i < n; i++) {
    sum += i;
  }
}

int main() {
  typedef struct City {
    char *name;
    int lat;
    int lon;
  } city_t;
  // print_sizes();
  city_t c = {.name = "San Fransisco", .lat = 37, .lon = -122};

  printf("%s\n", c.name);
  printf("Memory address of c is: %p\n", &c);
  printf("Size of memory address: %zu\n", sizeof(&c));

  print_mem_addr((uintptr_t)&c);

  printf("Size of City struct: %zu\n", sizeof(city_t));

  return 0;
}
