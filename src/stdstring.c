#include <string.h>
#include <stdlib.h>
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

static char *init_char_array(size_t size) {
  char *data = safe_array_malloc(char, size);
  memset(data, '\0', size);
  return data;
}

void string_reserve(StringRef self, const size_t length) {
  const size_t capacity = length + 1;
  if (string_capacity(self) >= capacity) {
    return;
  } else {
    const size_t end = min_size_t(string_length(self), length);
    char *data = init_char_array(capacity);
    strncpy(data, string_data(self), end);

    safe_free(self->data_);
    self->data_ = data;
    self->length_ = end;
    self->capacity_ = capacity;
  }
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

StringRef make_string(const char *string) {
  const size_t capacity = strlen(string) + 1;
  StringRef value = safe_malloc(struct String);
  value->data_ = init_char_array(capacity);
  strcpy(value->data_, string);
  value->length_ = strlen(string);
  value->capacity_ = capacity;
  return value;
}

int string_compare(StringRef lhs, StringRef rhs) {
  return strcmp(string_data(lhs), string_data(rhs));
}
