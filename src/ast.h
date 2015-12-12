#ifndef KMC_C89_COMPILER_AST_H
#define KMC_C89_COMPILER_AST_H

#include "utility.h"

enum AstTag {
  AST_IDENTIFIER,
  AST_INTEGER_CONSTANT,
  AST_FLOATING_CONSTANT,
  AST_CHARACTER_CONSTANT,
  AST_STRING_LITERAL,
  AST_TAG_ENUM_END
};

typedef struct Ast* AstRef;

bool is_identifier(AstRef ast);
bool is_integer_constant(AstRef ast);
bool is_floating_constant(AstRef ast);
bool is_character_constant(AstRef ast);
bool is_string_literal(AstRef ast);

AstRef make_ast_identifier(const char* src, size_t length);
AstRef make_ast_integer_constant(const char* src, size_t length);
AstRef make_ast_floating_constant(const char* src, size_t length);
AstRef make_ast_character_constant(const char* src, size_t length);
AstRef make_ast_string_literal(const char* src, size_t length);

#endif  /* KMC_C89_COMPILER_AST_H */
