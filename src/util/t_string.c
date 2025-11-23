#include "t_string.h"
#include <stdio.h>
#include <string.h>

void concat_strings(char *str1, char *str2) {
  int str1_last_index = find_last_index(str1);
  printf("End of string using strlen: %llu\n", strlen(str1));
  printf("String 1 last index: %d", str1_last_index);
}

int find_last_index(char *str) { return strlen(str); }
