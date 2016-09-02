#include "sexpr.h"
#include "sexpr_pool.h"

bool is_nil(SexprRef sexpr) {
  return sexpr == NULL;
}

bool is_atom(SexprRef sexpr) {
  return is_nil(sexpr) || sexpr->tag != SEXPR_CONS;
}

bool is_integer(SexprRef sexpr) {
  return !is_nil(sexpr) && sexpr->tag == SEXPR_INTEGER;
}

bool is_symbol(SexprRef sexpr) {
  return !is_nil(sexpr) && sexpr->tag == SEXPR_SYMBOL;
}

bool is_ast(SexprRef sexpr) {
  return !is_nil(sexpr) && sexpr->tag == SEXPR_AST;
}

SexprRef cons(SexprRef car, SexprRef cdr) {
  SexprRef result = palloc(struct Sexpr, sexpr_pool(), 1);
  result->tag = SEXPR_CONS;
  result->data.cons.car = car;
  result->data.cons.cdr = cdr;
  return result;
}

SexprRef car(SexprRef sexpr) {
  assert(!is_atom(sexpr));
  return sexpr->data.car;
}

SexprRef cdr(SexprRef sexpr) {
  assert(!is_atom(sexpr));
  return sexpr->data.cdr;
}

SexprRef make_integer(IntegerData integer) {
  SexprRef result = palloc(struct Sexpr, sexpr_pool(), 1);
  result->tag = SEXPR_INTEGER;
  result->data.integer = integer;
  return result;
}

IntegerData get_integer(SexprRef sexpr) {
  assert(is_integer(sexpr));
  return sexpr->data.integer;
}

SexprRef make_symbol(SymbolData symbol) {
  SexprRef result = palloc(struct Sexpr, sexpr_pool(), 1);
  result->tag = SEXPR_SYMBOL;
  result->data.symbol = symbol;
  return result;
}

StringRef get_symbol(SexprRef sexpr) {
  assert(is_symbol(sexpr));
  return sexpr->data.symbol;
}

SexprRef make_ast(AstData ast) {
  SexprRef result = palloc(struct Sexpr, sexpr_pool(), 1);
  result->tag = SEXPR_AST;
  result->data.ast = ast;
  return result;
}

AstData get_ast(SexprRef sexpr) {
  assert(is_ast(sexpr));
  return sexpr->data.ast;
}
