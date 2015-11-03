#ifndef KMC_C89_COMPILER_STDSTRING_H
#define KMC_C89_COMPILER_STDSTRING_H

struct String {
  char* dat;
  size_t leng;
  size_t cap;
};

typedef struct String* StringRef;

#endif  /* KMC_C89_COMPILER_STDSTRING_H */
