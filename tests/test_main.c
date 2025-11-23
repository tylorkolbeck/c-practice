#include "munit/munit.h"

extern MunitSuite string_suite;

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  MunitSuite suites[] = {string_suite, {NULL, NULL, NULL, 0, 0}};
  // Run all tests
  return munit_suite_main(suites, NULL, argc, argv);
}
