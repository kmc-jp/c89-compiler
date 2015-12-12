#ifndef KMC_C89_COMPILER_AST_METHOD_H
#define KMC_C89_COMPILER_AST_METHOD_H

#include "ast.h"
#include "ast/token.h"
#include "utility.h"

IdentifierRef get_identifier(AstRef ast);
IntegerConstantRef get_integer_constant(AstRef ast);
FloatingConstantRef get_floating_constant(AstRef ast);
CharacterConstantRef get_character_constant(AstRef ast);
StringLiteralRef get_string_literal(AstRef ast);

AstRef make_ast_identifier(const char* src, size_t length);
AstRef make_ast_integer_constant(const char* src, size_t length);
AstRef make_ast_floating_constant(const char* src, size_t length);
AstRef make_ast_character_constant(const char* src, size_t length);
AstRef make_ast_string_literal(const char* src, size_t length);

#endif  /* KMC_C89_COMPILER_AST_METHOD_H */