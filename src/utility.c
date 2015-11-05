#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

void* safe_malloc_impl(size_t size) {
  void* ptr = malloc(size);
  if (!ptr) {
    fprintf(stderr, "malloc error: failed to allocate memory\n");
    exit(EXIT_FAILURE);
  }
  return ptr;
}
void safe_free_impl(void* ptr) {
  free(ptr);
}

size_t enough_capacity(size_t size) {
  size_t capacity = 1;
  while (capacity < size) {
    capacity *= 2;
  }
  return capacity;
}

size_t min_size_t(size_t a, size_t b) {
  return a < b ? a : b;
}
size_t max_size_t(size_t a, size_t b) {
  return a < b ? b : a;
}
