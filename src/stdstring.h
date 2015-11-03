#ifndef KMC_C89_COMPILER_STDSTRING_H
#define KMC_C89_COMPILER_STDSTRING_H

struct String {
  char* data_;
  size_t length_;
  size_t capacity_;
};

typedef struct String* StringRef;

#endif  /* KMC_C89_COMPILER_STDSTRING_H */
