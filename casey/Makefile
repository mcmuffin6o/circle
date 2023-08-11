# Name directories
SRC_DIR := src
BUILD_DIR := build
OBJ_DIR := ${BUILD_DIR}/obj
DEP_DIR := ${BUILD_DIR}/dep
CPPCHECK_DIR := ${BUILD_DIR}/cppcheck
BUILD_DIRS := ${BUILD_DIR} ${OBJ_DIR} ${DEP_DIR} ${CPPCHECK_DIR}

# Name executable
BIN := ${BUILD_DIR}/circle

# List directories where header files are found
_INCLUDE := include
INCLUDE := ${_INCLUDE:%=-I%}

# Make obj and dep files per source file
SRC := $(wildcard ${SRC_DIR}/*.c)  # Sneaky trick to get all .c in a directory
OBJ := ${SRC:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
DEP := ${OBJ:${OBJ_DIR}/%.o=${DEP_DIR}/%.d}

# Compiler, preprocessor, and linker setup
CC := gcc
CCFLAGS := -Wall -Wextra -Wshadow
CPPFLAGS = -MP -MMD -MT $@ -MF ${DEP_DIR}/$*.d  # Note: uses = instead of :=
LDFLAGS :=

# Debug configuration
CCFLAGS += -g -O

# Release configuration
# CCFLAGS += -O3
# CPPFLAGS += -DRELEASE -DNDEBUG

# If "make" or "make all" is called, check and make the executable.
.PHONY: all
all: ${BIN}

# Run under valgrind
.PHONY: memcheck
memcheck: all
	valgrind --leak-check=yes ${BIN} ${ARGS}

# If "make run" is called, make the executable and run it
.PHONY: run
run: all
	${BIN} ${ARGS}

# Delete all object files, all dep files, and the executable
.PHONY: clean
clean:
	rm -rf ${BUILD_DIR}

# Link the object files to build the executable
${BIN}: ${OBJ}
	${CC} ${LDFLAGS} $^ -o $@

# Compile the source files into object files
${OBJ}: ${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${BUILD_DIRS}
	# cppcheck --enable=warning --cppcheck-build-dir=${CPPCHECK_DIR} --quiet --error-exitcode=1 $<
	cppcheck --enable=warning --cppcheck-build-dir=${CPPCHECK_DIR} --quiet $<
	${CC} ${CCFLAGS} ${CPPFLAGS} ${INCLUDE} -c $< -o $@

# Create the required directories if they don't already exist
${BUILD_DIRS}:
	mkdir -p $@

# The dash makes make not fail if .d file not found
-include ${DEP}
