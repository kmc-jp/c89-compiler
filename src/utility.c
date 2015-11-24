#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void memory_copy(void* dst, const void* src, size_t size, size_t count) {
  if (0 < count) {
    assert(dst && src);
    memcpy(dst, src, size * count);
  }
}
void memory_move(void* dst, const void* src, size_t size, size_t count) {
  if (0 < count) {
    assert(dst && src);
    memmove(dst, src, size * count);
  }
}
