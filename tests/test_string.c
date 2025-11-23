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

// static MunitResult test_concat_string(const MunitParameter params[],
//                                       void *data) {
//   (void)params;
//   (void)data;
//
//   char *str1 = "Hello";
//   char *str2 = " world";
//   char *expect = "Hell world";
//   strcat(str1, str2);
//
//   concat_strings(str1, str2);
//   munit_assert_string_equal(str1, expect);
// }

MunitTest string_tests[] = {
    {"/find_last_index", test_find_last_index, NULL, NULL, 0, NULL},
    {"/empt_string", test_find_last_index_empty_str, NULL, NULL, 0, NULL},
    {NULL, NULL, NULL, NULL, 0, NULL}};

MunitSuite string_suite = {"/string", string_tests, NULL, 1, 0};
