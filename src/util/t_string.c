#include "t_string.h"
#include <stdio.h>
#include <string.h>

/*
 * concat_strings
 * --------------
 *
 *  Appends the null-terminated string `str2` to the end of the writable
 *  string buffer `str1`. The concatenation is performed in place.
 *
 * Requirements / Assumptions
 *  - `str1` must point to a writable character buffer.
 *  - `str1` must have enough unused space to hold all characters of `str2`
 *    plus a null terminator. No bounds checking is performed.
 *  - `str2` must be a valid null-terminated string, but does not need to
 *    be writable.
 *
 * Behavior:
 *  - The contents of `str1` are modified; `str2` is left unchanged.
 *  - If `str2` is empty, `str1` remains the same.
 *  - If `str1` is empty, the result becomes a copy of `str2`.
 *
 *  This function mirrors the behavior of `strcat`, but is implemented manually
 *  to illustrate pointer iteration and in-place string manupulation.
 */
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

#include <stddef.h> // for size_t
#include <string.h> // optional, for NULL if needed

/*
 * reverse_string
 * --------------
 * Reverses the characters in the given null-terminated string IN PLACE.
 *
 * Requirements:
 *   - Use two pointers: one starting at the beginning of the string and
 *     one at the last character before the null terminator.
 *   - Swap characters while moving the pointers toward each other.
 *   - Stop when the pointers meet or cross.
 *
 * Behavior:
 *   - The input must be a writable character buffer (char array), not a
 *     string literal.
 *   - An empty string or a 1-character string remains unchanged.
 */
void reverse_string(char *str) {
  char *end = str;

  while (*end != '\0') {
    end++;
  }

  end--;

  // If end and start are the same then that means only one char passed
  if (str == end || *str == '\0') {
    return;
  }
  while (str <= end) {
    char temp = *str;
    *str = *end;
    *end = temp;
    str++;
    end--;
  }
}

/*
 * count_char
 * ----------
 * Counts the number of occurrences of a given character 'ch'
 * inside the null-terminated string 'str'.
 *
 * Requirements:
 *   - Use a pointer that walks through the string until '\0'.
 *   - Compare each character using dereferencing (*ptr).
 *   - Return how many characters match 'ch'.
 *
 * Behavior:
 *   - Returns 0 if the character does not appear.
 *   - Returns 0 for an empty string.
 */
int count_char(const char *str, char ch) {
  int c = 0;
  while (*str != '\0') {
    if (*str == ch)
      c++;
    str++;
  }
  return c;
}

/*
 * copy_string
 * -----------
 * Copies the characters from 'src' into 'dest', including the final
 * null terminator.
 *
 * Requirements:
 *   - Use two pointers: one reading from src, one writing to dest.
 *   - Copy characters until reaching src's '\0'.
 *   - Write a '\0' into dest when finished.
 *
 * Behavior:
 *   - 'dest' must be a writable buffer large enough to hold the copy.
 *   - The function must not modify the contents of 'src'.
 */
void copy_string(char *dest, const char *src) {
  // TODO: implement
}

/*
 * sum_array
 * ---------
 * Computes the sum of the first 'len' integers in the array 'arr'.
 *
 * Requirements:
 *   - Use a pointer to iterate through the array elements.
 *   - Add each dereferenced integer to the sum.
 *
 * Behavior:
 *   - Returns 0 if len is 0.
 *   - Does not modify the array.
 */
int sum_array(const int *arr, size_t len) {
  // TODO: implement
  return 0;
}

/*
 * max_element
 * -----------
 * Returns the largest integer in the array 'arr', based on 'len'
 * elements.
 *
 * Requirements:
 *   - Use a pointer to walk the array.
 *   - Track the maximum value seen so far.
 *
 * Behavior:
 *   - len must be at least 1 for the result to be valid.
 *   - Does not modify the array.
 */
int max_element(const int *arr, size_t len) {
  // TODO: implement
  return 0;
}

/*
 * my_strlen
 * ---------
 * Computes the length of a null-terminated string, not counting the
 * terminating '\0'.
 *
 * Requirements:
 *   - Use a pointer to scan forward until '\0'.
 *   - Compute length as the number of characters before the terminator.
 *
 * Behavior:
 *   - Returns 0 for an empty string.
 *   - Equivalent to strlen(), but implemented manually.
 */
size_t my_strlen(const char *str) {
  // TODO: implement
  return 0;
}

/*
 * my_strchr
 * ---------
 * Returns a pointer to the first occurrence of the character 'ch'
 * inside the null-terminated string 'str'.
 *
 * Requirements:
 *   - Walk the string using a pointer.
 *   - Return the address where *ptr == ch.
 *
 * Behavior:
 *   - If 'ch' is found, return a pointer to that character.
 *   - If 'ch' is '\0', return a pointer to the terminating null byte.
 *   - If the character does not appear, return NULL.
 */
char *my_strchr(const char *str, int ch) {
  // TODO: implement
  return NULL;
}

int find_last_index(char *str) { return strlen(str); }
