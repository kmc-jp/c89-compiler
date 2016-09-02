#ifndef KMC_C90_COMPILER_SEXPR_H
#define KMC_C90_COMPILER_SEXPR_H

#include "ast.h"
#include "utility.h"

enum SexprTag {
  SEXPR_CONS, SEXPR_INTEGER, SEXPR_SYMBOL, SEXPR_AST
};

struct Sexpr;

struct ConsData {
  struct Sexpr* car;
  struct Sexpr* cdr;
};

typedef long long IntegerData;
typedef StringRef SymbolData;
typedef AstTag AstData;

struct Sexpr {
  enum SexprTag tag;
  union Data {
    struct ConsData cons;  /* SEXPR_CONS */
    IntegerData integer;   /* SEXPR_INTEGER */
    SymbolData symbol;     /* SEXPR_SYMBOL */
    AstData ast;           /* SEXPR_AST */
  } data;
};

bool is_nil(struct Sexpr* sexpr);
bool is_atom(struct Sexpr* sexpr);
bool is_integer(struct Sexpr* sexpr);
bool is_symbol(struct Sexpr* sexpr);
bool is_ast(struct Sexpr* sexpr);
struct Sexpr* cons(struct Sexpr* car, struct Sexpr* cdr);
struct Sexpr* car(struct Sexpr* sexpr);
struct Sexpr* cdr(struct Sexpr* sexpr);
struct Sexpr* make_integer(IntegerData integer);
IntegerData get_integer(struct Sexpr* sexpr);
struct Sexpr* make_symbol(SymbolData symbol);
SymbolData get_symbol(struct Sexpr* sexpr);

#endif  /* KMC_C90_COMPILER_SEXPR_H */
