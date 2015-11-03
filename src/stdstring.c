#include <string.h>
#include "stdstring.h"
#include "utility.h"

size_t string_length(StringRef self) {
  return self->length_;
}

size_t string_capacity(StringRef self) {
  return self->capacity_;
}

char *string_data(StringRef self) {
  return self->data_;
}

size_t min_size_t(size_t a, size_t b) {
  return (a < b ? a:b);
}

void string_resize(StringRef self, size_t length) {
  size_t capacity = length + 1;
  size_t end = min_size_t(self->length_, length);
  char *data = safe_malloc(sizeof(char) * capacity);
  strncpy(data, self->data_, end);
  data[end] = '\0';

  self->data_ = data;
  self->length_ = end;
  self->capacity_ = capacity;
}

size_t string_copy(StringRef self, StringRef src, size_t length, size_t index) {
  length = min_size_t(length, string_length(src));
  string_resize(self, length);
  strncpy(string_data(self), string_data(src) + index, length);
}

void string_append(StringRef self, StringRef after) {
  size_t oldlength = string_length(self);
  size_t length = string_length(self) + string_length(after);
  char *data;
  string_resize(self, length);
  data = string_data(self);
  strcpy(data + oldlength, string_data(after));
}

char* string_at(StringRef self, int index) {
  return string_data(self) + index;
}
