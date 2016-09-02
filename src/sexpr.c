#include "sexpr.h"
#include "sexpr_pool.h"

bool is_nil(struct Sexpr* sexpr) {
  return sexpr == NULL;
}

bool is_cons(struct Sexpr* sexpr) {
  if (is_nil(sexpr)) {
    return false;
  } else {
    return sexpr->tag == SEXPR_CONS;
  }
}

struct Sexpr* cons(struct Sexpr* car, struct Sexpr* cdr) {
  struct Sexpr* result = palloc(struct Sexpr, sexpr_pool(), 1);
  result->tag = SEXPR_CONS;
  result->data.cons.car = car;
  result->data.cons.cdr = cdr;
  return result;
}
