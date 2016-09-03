#include "sexpr.h"
#include "sexpr_pool.h"

static SexprRef new_sexpr(void) {
  return palloc(struct Sexpr, sexpr_pool(), 1);
}

bool is_nil(SexprRef sexpr) {
  return sexpr == NULL;
}

bool is_atom(SexprRef sexpr) {
  return is_nil(sexpr) || sexpr->tag != SEXPR_CONS;
}

bool is_symbol(SexprRef sexpr) {
  return !is_nil(sexpr) && sexpr->tag == SEXPR_SYMBOL;
}

bool is_ast(SexprRef sexpr) {
  return !is_nil(sexpr) && sexpr->tag == SEXPR_AST;
}

SexprRef cons(SexprRef car, SexprRef cdr) {
  SexprRef result = new_sexpr();
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

SexprRef new_symbol(const char* src, size_t length) {
  AllocatorRef allocator = string_pool_allocator(sexpr_pool());
  StringRef symbol = make_string(src, length, allocator);
  return make_symbol(symbol);
}

SexprRef make_symbol(SymbolData symbol) {
  SexprRef result = new_sexpr();
  result->tag = SEXPR_SYMBOL;
  result->data.symbol = symbol;
  return result;
}

StringRef get_symbol(SexprRef sexpr) {
  assert(is_symbol(sexpr));
  return sexpr->data.symbol;
}

SexprRef make_ast(AstData ast) {
  SexprRef result = new_sexpr();
  result->tag = SEXPR_AST;
  result->data.ast = ast;
  return result;
}

AstData get_ast(SexprRef sexpr) {
  assert(is_ast(sexpr));
  return sexpr->data.ast;
}
