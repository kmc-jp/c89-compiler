#include "sexpr.h"
#include "sexpr_pool.h"

struct Sexpr* cons(struct Sexpr* car, struct Sexpr* cdr) {
  struct Sexpr* result = palloc(struct Sexpr, sexpr_pool(), 1);
  result->tag = SEXPR_CONS;
  result->data.cons.car = car;
  result->data.cons.cdr = cdr;
  return result;
}
