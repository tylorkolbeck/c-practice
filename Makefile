CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra -g
CPPFLAGS := -Iincludes -Isrc
LDFLAGS  :=
LDLIBS   :=

SRC_DIR  := src
OUT_DIR  := out

MUNIT_SRC := includes/munit/munit.c
MUNIT_OBJ := $(OUT_DIR)/munit/munit.o

# -----------------------------------------------------------------------------
# Collect source files
# -----------------------------------------------------------------------------
SRCS := $(wildcard $(SRC_DIR)/*.c) \
        $(wildcard $(SRC_DIR)/*/*.c)

# Turn e.g. src/main.c                -> out/main.o
#           src/benchmark/benchmark.c  -> out/benchmark/benchmark.o
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OUT_DIR)/%.o,$(SRCS))

TARGET := $(OUT_DIR)/main.exe

# All unique directories that will contain .o files
OBJ_DIRS := $(sort $(dir $(OBJS)) $(OUT_DIR)/munit)

# Separate app main from library code
APP_SRC  := $(SRC_DIR)/main.c
APP_OBJ  := $(OUT_DIR)/main.o
LIB_SRCS := $(filter-out $(APP_SRC),$(SRCS))
LIB_OBJS := $(filter-out $(APP_OBJ),$(OBJS))

# -----------------------------------------------------------------------------
# Test files – single test runner
# -----------------------------------------------------------------------------
TEST_DIR     := tests
TEST_SRCS    := $(wildcard $(TEST_DIR)/*.c)

TEST_OUT_DIR := $(OUT_DIR)/tests
TEST_OBJS    := $(patsubst $(TEST_DIR)/%.c,$(TEST_OUT_DIR)/%.o,$(TEST_SRCS))
TEST_BIN     := $(TEST_OUT_DIR)/tests.exe

# Ensure test output dir exists
$(TEST_OUT_DIR):
	@if not exist "$@" mkdir "$@"

# Compile test .c -> out/tests/*.o
$(TEST_OUT_DIR)/%.o: $(TEST_DIR)/%.c | $(TEST_OUT_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Compile munit.c -> out/munit/munit.o
$(MUNIT_OBJ): $(MUNIT_SRC) | $(OBJ_DIRS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Single test executable:
#   - all test objects (one of them should define main: tests/test_main.c)
#   - all library objects, BUT NOT main.o
#   - munit.o (for munit_suite_main, etc.)
$(TEST_BIN): $(TEST_OBJS) $(LIB_OBJS) $(MUNIT_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# -----------------------------------------------------------------------------
# Default target
# -----------------------------------------------------------------------------
all: $(TARGET)

# Link step for app
$(TARGET): $(APP_OBJ) $(LIB_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# -----------------------------------------------------------------------------
# Compile rule (mirrored directories) for src/
# -----------------------------------------------------------------------------
$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# -----------------------------------------------------------------------------
# Create all needed output directories (Windows-friendly)
# -----------------------------------------------------------------------------
$(OBJ_DIRS):
	@if not exist "$@" mkdir "$@"

# -----------------------------------------------------------------------------
# Convenience targets
# -----------------------------------------------------------------------------
run: $(TARGET)
	./$(TARGET)

clean:
	@if exist "$(OUT_DIR)" rmdir /S /Q "$(OUT_DIR)"

build: $(TARGET)
	@echo "Build completed successfully."

test: $(TEST_BIN)
	@echo "Running tests..."
	@./$(TEST_BIN) --color always
	@echo "All tests passed!"

.PHONY: all run clean build test

