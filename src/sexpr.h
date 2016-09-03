#ifndef KMC_C90_COMPILER_SEXPR_H
#define KMC_C90_COMPILER_SEXPR_H

#include "ast.h"
#include "utility.h"

struct Sexpr;
typedef struct Sexpr* SexprRef;
typedef StringRef SymbolData;
typedef AstTag AstData;

enum SexprTag {
  SEXPR_CONS, SEXPR_SYMBOL, SEXPR_AST
};

struct ConsData {
  SexprRef car;
  SexprRef cdr;
};

struct Sexpr {
  enum SexprTag tag;
  union Data {
    struct ConsData cons;  /* SEXPR_CONS */
    SymbolData symbol;     /* SEXPR_SYMBOL */
    AstData ast;           /* SEXPR_AST */
  } data;
};

bool sexpr_is_nil(SexprRef sexpr);
bool sexpr_is_atom(SexprRef sexpr);
bool sexpr_is_symbol(SexprRef sexpr);
bool sexpr_is_ast(SexprRef sexpr);
SexprRef cons(SexprRef car, SexprRef cdr);
SexprRef car(SexprRef sexpr);
SexprRef cdr(SexprRef sexpr);
SexprRef sexpr_new_symbol(const char* src, size_t length);
SexprRef sexpr_make_symbol(SymbolData symbol);
SymbolData sexpr_get_symbol(SexprRef sexpr);
SexprRef sexpr_make_ast(AstData ast);
AstData sexpr_get_ast(SexprRef sexpr);

#endif  /* KMC_C90_COMPILER_SEXPR_H */
