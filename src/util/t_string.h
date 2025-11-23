#pragma once
#include <stddef.h>


void concat_strings(char *str1, const char *str2);
int find_last_index(char *str);

void   reverse_string(char *str);
int    count_char(const char *str, char ch);
void   copy_string(char *dest, const char *src);
int    sum_array(const int *arr, size_t len);
int    max_element(const int *arr, size_t len);
size_t my_strlen(const char *str);
char  *my_strchr(const char *str, int ch);

