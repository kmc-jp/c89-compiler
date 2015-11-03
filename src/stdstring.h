#ifndef KMC_C89_COMPILER_STDSTRING_H
#define KMC_C89_COMPILER_STDSTRING_H

struct string_entity {
  char* dat;
  size_t leng;
  size_t cap;
};

typedef struct string_entity* string;

#endif  /* KMC_C89_COMPILER_STDSTRING_H */
