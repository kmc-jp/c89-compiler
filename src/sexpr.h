#ifndef KMC_C90_COMPILER_SEXPR_H
#define KMC_C90_COMPILER_SEXPR_H

#include "utility.h"

enum SexprTag {
  SEXPR_CONS, SEXPR_INTEGER
};

struct Sexpr;

struct ConsData {
  struct Sexpr* car;
  struct Sexpr* cdr;
};

typedef long long IntegerData;

struct Sexpr {
  enum SexprTag tag;
  union Data {
    struct ConsData cons;
    IntegerData integer;
  } data;
};

bool is_nil(struct Sexpr* sexpr);
bool is_atom(struct Sexpr* sexpr);
struct Sexpr* cons(struct Sexpr* car, struct Sexpr* cdr);
struct Sexpr* car(struct Sexpr* sexpr);
struct Sexpr* cdr(struct Sexpr* sexpr);

#endif  /* KMC_C90_COMPILER_SEXPR_H */
