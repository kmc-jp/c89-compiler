#include "sexpr.h"
#include "sexpr_pool.h"

bool is_nil(struct Sexpr* sexpr) {
  return sexpr == NULL;
}

bool is_atom(struct Sexpr* sexpr) {
  return is_nil(sexpr) || sexpr->tag != SEXPR_CONS;
}

bool is_integer(struct Sexpr* sexpr) {
  return !is_nil(sexpr) && sexpr->tag == SEXPR_INTEGER;
}

struct Sexpr* cons(struct Sexpr* car, struct Sexpr* cdr) {
  struct Sexpr* result = palloc(struct Sexpr, sexpr_pool(), 1);
  result->tag = SEXPR_CONS;
  result->data.cons.car = car;
  result->data.cons.cdr = cdr;
  return result;
}

struct Sexpr* car(struct Sexpr* sexpr) {
  assert(!is_atom(sexpr));
  return sexpr->data.car;
}

struct Sexpr* cdr(struct Sexpr* sexpr) {
  assert(!is_atom(sexpr));
  return sexpr->data.cdr;
}
