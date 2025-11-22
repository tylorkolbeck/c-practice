#include "munit.h"
// void test_loop(void *arg) {
//   long n = *(long *)arg;
//
//   volatile long long sum = 0;
//   for (long i = 0; i < n; i++) {
//     sum += i;
//   }
// }

float get_average(int x, int y, int z) { return (x + y + z) / 3.0f; }

static MunitResult test_get_average(const MunitParameter params[], void *data) {
  float result = get_average(3, 4, 5);
  munit_assert_double(result, ==, 4.0);

  return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/get_average", test_get_average, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite suite = {"/average_tests", tests, NULL, 1,
                                 MUNIT_SUITE_OPTION_NONE};

int main(int argc, char *argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}
