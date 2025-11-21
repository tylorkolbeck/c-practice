#pragma once
typedef void (*bench_fn)(void *arg);

double benchmark(bench_fn fn, void *arg, long iterations);


