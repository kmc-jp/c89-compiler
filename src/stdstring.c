#include <string.h>
#include "stdstring.h"
#include "utility.h"

size_t string_length(StringRef str) {
  return str->leng;
}

size_t string_capacity(StringRef str) {
  return str->cap;
}

char *string_data(StringRef str) {
  return str->dat;
}

size_t smin(size_t a, size_t b) {
  return (a < b ? a:b);
}

void string_resize(StringRef str, size_t leng) {
  size_t cap = leng + 1;
  size_t end = smin(str->leng, leng);
  char *dat = safe_malloc(sizeof(char) * cap);
  strncpy(dat, str->dat, end);
  dat[end] = '\0';

  str->dat = dat;
  str->leng = end;
  str->cap = cap;
}

size_t string_copy(StringRef target, StringRef src, size_t leng, size_t idx) {
  leng = smin(leng, string_length(src));
  string_resize(target, leng);
  strncpy(string_data(target), string_data(src) + idx, leng);
}

void string_append(StringRef bef, StringRef aft) {
  size_t oldleng = string_length(bef);
  size_t leng = string_length(bef) + string_length(aft);
  char *dat;
  string_resize(bef, leng);
  dat = string_data(bef);
  strcpy(dat + oldleng, string_data(aft));
}

char* string_at(StringRef str, int idx) {
  return string_data(str) + idx;
}
