#ifndef KMC_C90_COMPILER_SEXPR_H
#define KMC_C90_COMPILER_SEXPR_H

#include "ast.h"
#include "utility.h"

struct Sexpr;
typedef struct Sexpr* SexprRef;
typedef long long IntegerData;
typedef StringRef StringData;
typedef StringRef SymbolData;
typedef AstTag AstData;

enum SexprTag {
  SEXPR_CONS, SEXPR_INTEGER, SEXPR_STRING, SEXPR_SYMBOL, SEXPR_AST
};

struct ConsData {
  SexprRef car;
  SexprRef cdr;
};

struct Sexpr {
  enum SexprTag tag;
  union Data {
    struct ConsData cons;  /* SEXPR_CONS */
    IntegerData integer;   /* SEXPR_INTEGER */
    StringData string;     /* SEXPR_STRING */
    SymbolData symbol;     /* SEXPR_SYMBOL */
    AstData ast;           /* SEXPR_AST */
  } data;
};

bool is_nil(SexprRef sexpr);
bool is_atom(SexprRef sexpr);
bool is_integer(SexprRef sexpr);
bool is_symbol(SexprRef sexpr);
bool is_ast(SexprRef sexpr);
SexprRef cons(SexprRef car, SexprRef cdr);
SexprRef car(SexprRef sexpr);
SexprRef cdr(SexprRef sexpr);
SexprRef make_integer(IntegerData integer);
IntegerData get_integer(SexprRef sexpr);
SexprRef make_symbol(SymbolData symbol);
SymbolData get_symbol(SexprRef sexpr);
SexprRef make_ast(AstData ast);
AstData get_ast(SexprRef sexpr);

#endif  /* KMC_C90_COMPILER_SEXPR_H */
