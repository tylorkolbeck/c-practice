CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra -g
CPPFLAGS := -Iincludes -Iincludes/munit -Isrc/benchmark
LDFLAGS  :=
LDLIBS   :=

SRC_DIR  := src
TEST_DIR := tests
OUT_DIR  := out

# All .c files directly under src/ (main.c, size_of.c, etc.)
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
SRC_OBJS  := $(patsubst $(SRC_DIR)/%.c,$(OUT_DIR)/%.o,$(SRC_FILES))

# Benchmark source in subdir: src/benchmark/benchmark.c -> out/benchmark.o
BENCH_SRC := $(SRC_DIR)/benchmark/benchmark.c
BENCH_OBJ := $(OUT_DIR)/benchmark.o

# Munit (single .c file)
MUNIT_SRC := includes/munit/munit.c
MUNIT_OBJ := $(OUT_DIR)/munit.o

TARGET      := $(OUT_DIR)/main.exe
TEST_SRC    := $(TEST_DIR)/test_get_average.c
TEST_OBJ    := $(OUT_DIR)/test_get_average.o
TEST_TARGET := $(OUT_DIR)/test_average.exe

# Objects for main program: all src/*.c + benchmark.c + munit.c
OBJS      := $(SRC_OBJS) $(BENCH_OBJ) $(MUNIT_OBJ)
# Objects for tests: the test file + munit.c
TEST_OBJS := $(TEST_OBJ) $(MUNIT_OBJ)

# Default target -----------------------------------------------------------
all: $(TARGET)

# Ensure out/ exists
$(OUT_DIR):
	mkdir $(OUT_DIR) 2>NUL || true

# ---- Build main program --------------------------------------------------

$(TARGET): $(OUT_DIR) $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

# Compile any src/*.c to out/*.o
$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | $(OUT_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Benchmark object from src/benchmark/benchmark.c
$(BENCH_OBJ): $(BENCH_SRC) | $(OUT_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Munit object from includes/munit/munit.c
$(MUNIT_OBJ): $(MUNIT_SRC) | $(OUT_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# ---- Build tests ---------------------------------------------------------

tests: $(TEST_TARGET)

$(TEST_TARGET): $(OUT_DIR) $(TEST_OBJS)
	$(CC) $(LDFLAGS) -o $@ $(TEST_OBJS) $(LDLIBS)

$(TEST_OBJ): $(TEST_SRC) | $(OUT_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# ---- Utility targets -----------------------------------------------------

run: $(TARGET)
	./$(TARGET)

run-tests: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(OUT_DIR)/*.o $(OUT_DIR)/*.exe

.PHONY: all tests run run-tests clean

