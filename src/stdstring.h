#ifndef KMC_C89_COMPILER_STDSTRING_H
#define KMC_C89_COMPILER_STDSTRING_H

struct String {
  char* buf_;
  size_t length_;
  size_t capacity_;
};

typedef struct String* StringRef;

size_t string_length(StringRef self);
size_t string_capacity(StringRef self);
char *string_data(StringRef self);
void string_reserve(StringRef self, size_t length);
void string_copy(StringRef self, StringRef src);
void string_append(StringRef self, StringRef other);
char string_at(StringRef self, size_t index);
StringRef string_ctor(char *string);
int string_compare(StringRef lhs, StringRef rhs);
#endif  /* KMC_C89_COMPILER_STDSTRING_H */
