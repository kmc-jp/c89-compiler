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

size_t smin(size_t a, size_t b) {
  return (a < b ? a:b);
}

void string_resize(StringRef self, size_t leng) {
  size_t cap = leng + 1;
  size_t end = smin(self->length_, leng);
  char *dat = safe_malloc(sizeof(char) * cap);
  strncpy(dat, self->data_, end);
  dat[end] = '\0';

  self->data_ = dat;
  self->length_ = end;
  self->capacity_ = cap;
}

size_t string_copy(StringRef self, StringRef src, size_t leng, size_t idx) {
  leng = smin(leng, string_length(src));
  string_resize(self, leng);
  strncpy(string_data(self), string_data(src) + idx, leng);
}

void string_append(StringRef self, StringRef aft) {
  size_t oldleng = string_length(self);
  size_t leng = string_length(self) + string_length(aft);
  char *dat;
  string_resize(self, leng);
  dat = string_data(self);
  strcpy(dat + oldleng, string_data(aft));
}

char* string_at(StringRef self, int idx) {
  return string_data(self) + idx;
}
