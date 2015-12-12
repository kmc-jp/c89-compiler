#ifndef KMC_C89_COMPILER_AST_H
#define KMC_C89_COMPILER_AST_H

#include <stddef.h>

enum AstTag {
  AST_IDENTIFIER,
  AST_INTEGER_CONSTANT,
  AST_FLOATING_CONSTANT,
  AST_CHARACTER_CONSTANT,
  AST_STRING_LITERAL,
  AST_TAG_ENUM_END
};

typedef struct Ast* AstRef;

AstRef make_ast_identifier(const char* src, size_t length);
AstRef make_ast_integer_constant(const char* src, size_t length);
AstRef make_ast_floating_constant(const char* src, size_t length);

#endif  /* KMC_C89_COMPILER_AST_H */
