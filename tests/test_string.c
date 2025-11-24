#include "munit/munit.h"
#include "util/t_string.h"
#include <string.h>

static MunitResult test_find_last_index(const MunitParameter params[],
                                        void *data) {
  (void)params;
  (void)data;

  int idx = find_last_index("abc");
  munit_assert_int(idx, ==, 3);

  return MUNIT_OK;
}

static MunitResult test_find_last_index_empty_str(const MunitParameter params[],
                                                  void *data) {
  (void)params;
  (void)data;

  int idx = find_last_index("");
  munit_assert_int(idx, ==, 0);

  return MUNIT_OK;
}

static MunitResult test_concat_string(const MunitParameter params[],
                                      void *data) {
  (void)params;
  (void)data;

  char str1[32] = "Hello";
  char *str2 = " world";
  char expect[] = "Hello world";
  // strcat(str1, str2);

  concat_strings(str1, str2);
  munit_assert_string_equal(str1, expect);
  return MUNIT_OK;
}

// ****** test reverse_string ********
static MunitResult test_reverse_string_basic(const MunitParameter params[],
                                             void *data) {
  (void)params;
  (void)data;

  char buf[] = "hello";
  reverse_string(buf);

  munit_assert_string_equal(buf, "olleh");
  return MUNIT_OK;
}

static MunitResult test_reverse_string_even(const MunitParameter params[],
                                            void *data) {
  (void)params;
  (void)data;

  char buf[] = "good";
  reverse_string(buf);

  munit_assert_string_equal(buf, "doog");
  return MUNIT_OK;
}

static MunitResult test_reverse_string_empty(const MunitParameter params[],
                                             void *data) {
  (void)params;
  (void)data;

  char buf[] = "";
  reverse_string(buf);

  munit_assert_string_equal(buf, "");
  return MUNIT_OK;
}

static MunitResult
test_reverse_string_single_char(const MunitParameter params[], void *data) {
  (void)params;
  (void)data;

  char buf[] = "A";
  reverse_string(buf);

  munit_assert_string_equal(buf, "A");
  return MUNIT_OK;
}

// ******** test copy_string **********
static MunitResult test_copy_string_basic(const MunitParameter params[],
                                          void *data) {
  (void)params;
  (void)data;

  char dest[32];
  const char *src = "hello world";

  copy_string(dest, src);

  munit_assert_string_equal(dest, src);
  return MUNIT_OK;
}

static MunitResult test_copy_string_empty(const MunitParameter params[],
                                          void *data) {
  (void)params;
  (void)data;

  char dest[8];
  const char *src = "";

  copy_string(dest, src);

  munit_assert_string_equal(dest, "");
  return MUNIT_OK;
}

// ********** test sum_array *************static MunitResult
static MunitResult test_sum_array_basic(const MunitParameter params[],
                                        void *data) {
  (void)params;
  (void)data;

  int arr[] = {1, 2, 3, 4};
  int sum = sum_array(arr, 4);

  munit_assert_int(sum, ==, 10);
  return MUNIT_OK;
}

static MunitResult test_sum_array_empty(const MunitParameter params[],
                                        void *data) {
  (void)params;
  (void)data;

  int arr[] = {0}; // won't be read
  int sum = sum_array(arr, 0);

  munit_assert_int(sum, ==, 0);
  return MUNIT_OK;
}

// ******* test max_element ********
static MunitResult test_max_element_basic(const MunitParameter params[],
                                          void *data) {
  (void)params;
  (void)data;

  int arr[] = {5, 2, 9, 1, 7};
  int max = max_element(arr, 5);

  munit_assert_int(max, ==, 9);
  return MUNIT_OK;
}

static MunitResult test_max_element_single(const MunitParameter params[],
                                           void *data) {
  (void)params;
  (void)data;

  int arr[] = {42};
  int max = max_element(arr, 1);

  munit_assert_int(max, ==, 42);
  return MUNIT_OK;
}

// ******* test my_strlen ************
static MunitResult test_my_strlen_basic(const MunitParameter params[],
                                        void *data) {
  (void)params;
  (void)data;

  size_t len = my_strlen("hello");
  munit_assert_int((int)len, ==, 5);

  return MUNIT_OK;
}

static MunitResult test_my_strlen_empty(const MunitParameter params[],
                                        void *data) {
  (void)params;
  (void)data;

  size_t len = my_strlen("");
  munit_assert_int((int)len, ==, 0);

  return MUNIT_OK;
}

static MunitResult test_my_strlen_with_spaces(const MunitParameter params[],
                                              void *data) {
  (void)params;
  (void)data;

  size_t len = my_strlen("a b c");
  munit_assert_int((int)len, ==, 5);

  return MUNIT_OK;
}

// *********** test count_char *****************
static MunitResult test_count_char_basic(const MunitParameter params[],
                                         void *data) {
  (void)params;
  (void)data;

  int count = count_char("banana", 'a');
  munit_assert_int(count, ==, 3);

  return MUNIT_OK;
}

static MunitResult test_count_char_not_found(const MunitParameter params[],
                                             void *data) {
  (void)params;
  (void)data;

  int count = count_char("banana", 'x');
  munit_assert_int(count, ==, 0);

  return MUNIT_OK;
}

static MunitResult test_count_char_empty(const MunitParameter params[],
                                         void *data) {
  (void)params;
  (void)data;

  int count = count_char("", 'a');
  munit_assert_int(count, ==, 0);

  return MUNIT_OK;
}

// ******** test my_stchr ***********
static MunitResult test_my_strchr_found(const MunitParameter params[],
                                        void *data) {
  (void)params;
  (void)data;

  char str[] = "hello";
  char *p = my_strchr(str, 'l');

  munit_assert_ptr_equal(p, &str[2]); // first 'l' at index 2
  return MUNIT_OK;
}

static MunitResult test_my_strchr_not_found(const MunitParameter params[],
                                            void *data) {
  (void)params;
  (void)data;

  char str[] = "hello";
  char *p = my_strchr(str, 'z');

  munit_assert_null(p);
  return MUNIT_OK;
}

static MunitResult test_my_strchr_null_char(const MunitParameter params[],
                                            void *data) {
  (void)params;
  (void)data;

  char str[] = "hi";
  char *p = my_strchr(str, '\0');

  // by convention, strchr returns pointer to the terminator
  munit_assert_ptr_equal(p, &str[2]); // 'h' (0), 'i' (1), '\0' (2)
  return MUNIT_OK;
}

MunitTest string_tests[] = {
    {"/find_last_index", test_find_last_index, NULL, NULL, 0, NULL},
    {"/empty_string", test_find_last_index_empty_str, NULL, NULL, 0, NULL},
    {"/concat_string", test_concat_string, NULL, NULL, 0, NULL},

    {"/reverse/basic", test_reverse_string_basic, NULL, NULL, 0, NULL},
    {"/reverse/empty", test_reverse_string_empty, NULL, NULL, 0, NULL},
    {"/reverse/single_char", test_reverse_string_single_char, NULL, NULL, 0,
     NULL},
    {"/reverse/even", test_reverse_string_even, NULL, NULL, 0, NULL},

    {"/count_char/basic", test_count_char_basic, NULL, NULL, 0, NULL},
    {"/count_char/not_found", test_count_char_not_found, NULL, NULL, 0, NULL},
    {"/count_char/empty", test_count_char_empty, NULL, NULL, 0, NULL},

    {"/copy_string/basic", test_copy_string_basic, NULL, NULL, 0, NULL},
    {"/copy_string/empty", test_copy_string_empty, NULL, NULL, 0, NULL},

    {"/array/sum/basic", test_sum_array_basic, NULL, NULL, 0, NULL},
    {"/array/sum/empty", test_sum_array_empty, NULL, NULL, 0, NULL},

    {"/array/max/basic", test_max_element_basic, NULL, NULL, 0, NULL},
    {"/array/max/single", test_max_element_single, NULL, NULL, 0, NULL},

    {"/strlen/basic", test_my_strlen_basic, NULL, NULL, 0, NULL},
    {"/strlen/empty", test_my_strlen_empty, NULL, NULL, 0, NULL},
    {"/strlen/with_spaces", test_my_strlen_with_spaces, NULL, NULL, 0, NULL},

    {"/strchr/found", test_my_strchr_found, NULL, NULL, 0, NULL},
    {"/strchr/not_found", test_my_strchr_not_found, NULL, NULL, 0, NULL},
    {"/strchr/null_char", test_my_strchr_null_char, NULL, NULL, 0, NULL},
    {NULL, NULL, NULL, NULL, 0, NULL}};

MunitSuite string_suite = {"/string", string_tests, NULL, 1, 0};
