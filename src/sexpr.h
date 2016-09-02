#ifndef KMC_C90_COMPILER_SEXPR_H
#define KMC_C90_COMPILER_SEXPR_H

enum SexprTag {
  SEXPR_CONS
};

struct Sexpr;

struct ConsData {
  struct Sexpr* car;
  struct Sexpr* cdr;
};

struct Sexpr {
  enum SexprTag tag;
  union Data {
    struct ConsData cons;
  } data;
};

#endif  /* KMC_C90_COMPILER_SEXPR_H */
