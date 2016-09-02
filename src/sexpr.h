#ifndef KMC_C90_COMPILER_SEXPR_H
#define KMC_C90_COMPILER_SEXPR_H

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

struct Sexpr* cons(struct Sexpr* car, struct Sexpr* cdr);

#endif  /* KMC_C90_COMPILER_SEXPR_H */
