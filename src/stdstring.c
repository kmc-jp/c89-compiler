#include <string.h>
#include <stdlib.h>
#include "stdstring.h"
#include "utility.h"

size_t string_length(StringRef self) {
  return self->length_;
}

size_t string_capacity(StringRef self) {
  return self->capacity_;
}

char *string_data(StringRef self) {
  return self->buf_;
}


void string_reserve(StringRef self, size_t length) {
  const size_t capacity = length + 1;
  if (string_capacity(self) >= capacity) {
    return;
  } else {
    const size_t newlength = min_size_t(string_length(self), length);
    char *buf = safe_array_malloc(char, capacity);
    strncpy(buf, string_data(self), newlength);
    memset(buf + newlength, '\0', length - newlength);
    safe_free(self->buf_);
    self->buf_ = buf;
    self->length_ = newlength;
    self->capacity_ = capacity;
  }
}

void string_copy(StringRef self, StringRef src) {
  const size_t length = min_size_t(length, string_length(src));
  string_reserve(self, length);
  strncpy(string_data(self), string_data(src), length);
}

void string_append(StringRef self, StringRef other) {
  const size_t length = string_length(self);
  const size_t newlength = string_length(self) + string_length(other);
  char *buf;
  string_reserve(self, newlength);
  buf = string_data(self);
  strncpy(buf + length, string_data(other), string_length(other));
}

char string_at(StringRef self, size_t index) {
  const char *buf = string_data(self);
  return buf[index];
}

StringRef string_ctor(char *string) {
  const size_t capacity = strlen(string) + 1;
  StringRef value = safe_malloc(struct String);
  value->buf_ = safe_array_malloc(char, capacity);
  strcpy(value->buf_, string);
  value->length_ = strlen(string);
  value->capacity_ = capacity;
  return value;
}

int string_compare(StringRef lhs, StringRef rhs) {
  return strcmp(string_data(lhs), string_data(rhs));
}
