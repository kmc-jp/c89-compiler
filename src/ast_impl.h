#ifndef KMC_C89_COMPILER_AST_IMPL_H
#define KMC_C89_COMPILER_AST_IMPL_H

#include "ast.h"
#include "ast/token.h"
#include "ast/constant.h"

struct Ast {
  enum AstTag tag;
  union AstData {
    IdentifierRef identifier;
    IntegerConstantRef integer_constant;
    FloatingConstantRef floating_constant;
    CharacterConstantRef character_constant;
    StringLiteralRef string_literal;

    ConstantRef constant;
    EnumerationConstantRef enumeration_constant;

    void* dummy;
  } data;
};

#endif  /* KMC_C89_COMPILER_AST_IMPL_H */
