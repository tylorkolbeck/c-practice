#include "benchmark.h"
#include <windows.h>
// Usage example
// long wu_iterations = 1; long wu_loops = 1000;
// printf("Running warmup loop\n");
// double wuTime = benchmark(test_loop, &wu_loops, wu_iterations);

// long iterations = 1;
// long loop_count = 1000000;

// printf("Running benchmark on test_loop - iterations: %ld loops: %ld\n",
// iterations, loop_count);
// double time = benchmark(test_loop, &loop_count, iterations);

// printf("Time: %f seconds\n", time);

double benchmark(bench_fn fn, void *arg, long iterations) {
  LARGE_INTEGER freq, start, end;
  QueryPerformanceFrequency(&freq);

  QueryPerformanceCounter(&start);

  for (long i = 0; i < iterations; i++) {
    fn(arg);
  }

  QueryPerformanceCounter(&end);

  return (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
}
