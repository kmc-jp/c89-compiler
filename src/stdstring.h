#ifndef KMC_C89_COMPILER_STDSTRING_H
#define KMC_C89_COMPILER_STDSTRING_H

struct String {
  char* data_;
  size_t length_;
  size_t capacity_;
};

typedef struct String* StringRef;

size_t string_length(const StringRef self);
size_t string_capacity(const StringRef self);
char *string_data(const StringRef self);
void string_reserve(StringRef self, const size_t length);
void string_copy(StringRef self, const StringRef src);
void string_append(StringRef self, const StringRef after);
char string_at(StringRef self, size_t index);
StringRef make_string(const char *string);
int string_compare(const StringRef lhs, const StringRef rhs);
#endif  /* KMC_C89_COMPILER_STDSTRING_H */
