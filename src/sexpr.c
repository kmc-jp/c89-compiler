#include "sexpr.h"
#include <assert.h>
#include "allocator.h"
#include "sexpr_pool.h"

static SexprRef new_sexpr(void) {
  return palloc(struct Sexpr, sexpr_pool(), 1);
}

bool sexpr_is_nil(SexprRef sexpr) {
  return sexpr == NULL;
}

bool sexpr_is_atom(SexprRef sexpr) {
  return sexpr_is_nil(sexpr) || sexpr->tag != SEXPR_CONS;
}

bool sexpr_is_symbol(SexprRef sexpr) {
  return !sexpr_is_nil(sexpr) && sexpr->tag == SEXPR_SYMBOL;
}

bool sexpr_is_ast(SexprRef sexpr) {
  return !sexpr_is_nil(sexpr) && sexpr->tag == SEXPR_AST;
}

SexprRef cons(SexprRef car, SexprRef cdr) {
  SexprRef result = new_sexpr();
  result->tag = SEXPR_CONS;
  result->data.cons.car = car;
  result->data.cons.cdr = cdr;
  return result;
}

SexprRef car(SexprRef sexpr) {
  assert(!sexpr_is_atom(sexpr));
  return sexpr->data.car;
}

SexprRef cdr(SexprRef sexpr) {
  assert(!sexpr_is_atom(sexpr));
  return sexpr->data.cdr;
}

SexprRef sexpr_new_symbol(const char* src, size_t length) {
  AllocatorRef allocator = string_pool_allocator(sexpr_pool());
  StringRef symbol = make_string(src, length, allocator);
  return sexpr_make_symbol(symbol);
}

SexprRef sexpr_make_symbol(SymbolData symbol) {
  SexprRef result = new_sexpr();
  result->tag = SEXPR_SYMBOL;
  result->data.symbol = symbol;
  return result;
}

StringRef sexpr_get_symbol(SexprRef sexpr) {
  assert(sexpr_is_symbol(sexpr));
  return sexpr->data.symbol;
}

SexprRef sexpr_make_ast(AstData ast) {
  SexprRef result = new_sexpr();
  result->tag = SEXPR_AST;
  result->data.ast = ast;
  return result;
}

AstData sexpr_get_ast(SexprRef sexpr) {
  assert(sexpr_is_ast(sexpr));
  return sexpr->data.ast;
}
