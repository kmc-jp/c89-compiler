#ifndef KMC_C89_COMPILER_STDSTRING_H
#define KMC_C89_COMPILER_STDSTRING_H

struct String {
  char* data_;
  size_t length_;
  size_t capacity_;
};

typedef struct String* StringRef;

size_t string_length(StringRef self);
size_t string_capacity(StringRef self);
char *string_data(StringRef self);
void string_reserve(StringRef self, size_t length);
void string_copy(StringRef self, StringRef src);
void string_append(StringRef self, StringRef after);
char string_at(StringRef self, size_t index);
#endif  /* KMC_C89_COMPILER_STDSTRING_H */
