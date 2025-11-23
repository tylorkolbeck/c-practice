#include "t_string.h"
#include <string.h>

// Takes a reference to a buffer and another string and concates the second
// string to the buffer. The buffer is assumed to be large enough to fit the
// appended text.
void concat_strings(char *str1, const char *str2) {

  char *dst = str1;

  while (*dst != '\0') {
    dst++;
  }

  const char *src = str2;
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }

  *dst = '\0';
}

int find_last_index(char *str) { return strlen(str); }
