CC ?= gcc
CXX = g++

CFLAGS ?= -Wall -Wextra -O2

SRC_DIR = src
TESTS_DIR = tests
GTEST_DIR = $(TESTS_DIR)/gtest
GTEST_FLAGS = -Wno-missing-field-init -lpthread -I$(TESTS_DIR)

RM = rm -f

all:

test:

vector_int_test: gtest_main.o gtest-all.o vector.o vector_int.o vector_int_test.o
	$(CXX) -o $@ gtest_main.o gtest-all.o vector.o vector_int.o vector_int_test.o -lpthread

gtest_main.o: $(GTEST_DIR)/gtest_main.cc
	$(CXX) -c $(GTEST_DIR)/gtest_main.cc -I$(TESTS_DIR)

gtest-all.o: $(GTEST_DIR)/gtest-all.cc
	$(CXX) -c $(GTEST_DIR)/gtest-all.cc -Wno-missing-field-initializers -I$(TESTS_DIR)

vector.o: $(SRC_DIR)/vector.c
	$(CC) -c $(SRC_DIR)/vector.c

vector.o: $(SRC_DIR)/vector.h

vector_int.o: $(TESTS_DIR)/vector_int.c
	$(CC) -c $(TESTS_DIR)/vector_int.c

vector_int.o: $(SRC_DIR)/vector.h

vector_int_test.o: $(TESTS_DIR)/vector_int_test.cpp
	$(CXX) -c $(TESTS_DIR)/vector_int_test.cpp

vector_int_test.o: $(SRC_DIR)/vector.h

clean:
	$(RM) *.o

.PHONY: test clean
