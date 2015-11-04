#include <string.h>
#include "stdstring.h"
#include "utility.h"

size_t string_length(const StringRef self) {
  return self->length_;
}

size_t string_capacity(const StringRef self) {
  return self->capacity_;
}

char *string_data(const StringRef self) {
  return self->data_;
}

void string_reserve(StringRef self, const size_t length) {
  const size_t capacity = length + 1;
  const size_t end = min_size_t(string_length(self), length);
  size_t i;
  char *data;
  if (string_capacity(self) >= capacity) {
    return;
  }
  data = safe_array_malloc(char, capacity);
  strncpy(data, string_data(self), end);
  memset(data + end, '\0', capacity - end);

  self->data_ = data;
  self->length_ = end;
  self->capacity_ = capacity;
}

void string_copy(StringRef self, const StringRef src) {
  const size_t length = min_size_t(length, string_length(src));
  string_reserve(self, length);
  strncpy(string_data(self), string_data(src), length);
}

void string_append(StringRef self, const StringRef after) {
  const size_t oldlength = string_length(self);
  const size_t length = string_length(self) + string_length(after);
  char *data;
  string_reserve(self, length);
  data = string_data(self);
  strncpy(data + oldlength, string_data(after), string_length(after));
}

char string_at(const StringRef self, const size_t index) {
  const char *data = string_data(self);
  return data[index];
}
