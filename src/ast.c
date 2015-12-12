#include "ast.h"
#include <assert.h>
#include "ast_impl.h"
#include "ast/ast_pool.h"

AstRef ast_ctor(void) {
  AstRef ast = ast_palloc(struct Ast, 1);
  ast->tag = AST_TAG_ENUM_END;
  ast->data.dummy = NULL;
  return ast;
}


IdentifierRef get_identifier(AstRef ast) {
  assert(ast);
  if (ast->tag == AST_IDENTIFIER) {
    return ast->data.identifier;
  }
  return NULL;
}

IntegerConstantRef get_integer_constant(AstRef ast) {
  assert(ast);
  if (ast->tag == AST_INTEGER_CONSTANT) {
    return ast->data.integer_constant;
  }
  return NULL;
}

FloatingConstantRef get_floating_constant(AstRef ast) {
  assert(ast);
  if (ast->tag == AST_FLOATING_CONSTANT) {
    return ast->data.floating_constant;
  }
  return NULL;
}

CharacterConstantRef get_character_constant(AstRef ast) {
  assert(ast);
  if (ast->tag == AST_CHARACTER_CONSTANT) {
    return ast->data.character_constant;
  }
  return NULL;
}

StringLiteralRef get_string_literal(AstRef ast) {
  assert(ast);
  if (ast->tag == AST_STRING_LITERAL) {
    return ast->data.string_literal;
  }
  return NULL;
}


AstRef make_ast_identifier(const char* src, size_t length) {
  AstRef ast = ast_ctor();
  ast->tag = AST_IDENTIFIER;
  ast->data.identifier = make_identifier(src, length);
  return ast;
}

AstRef make_ast_integer_constant(const char* src, size_t length) {
  AstRef ast = ast_ctor();
  ast->tag = AST_INTEGER_CONSTANT;
  ast->data.integer_constant = make_integer_constant(src, length);
  return ast;
}

AstRef make_ast_floating_constant(const char* src, size_t length) {
  AstRef ast = ast_ctor();
  ast->tag = AST_FLOATING_CONSTANT;
  ast->data.floating_constant = make_floating_constant(src, length);
  return ast;
}

AstRef make_ast_character_constant(const char* src, size_t length) {
  AstRef ast = ast_ctor();
  ast->tag = AST_CHARACTER_CONSTANT;
  ast->data.character_constant = make_character_constant(src, length);
  return ast;
}

AstRef make_ast_string_literal(const char* src, size_t length) {
  AstRef ast = ast_ctor();
  ast->tag = AST_STRING_LITERAL;
  ast->data.string_literal = make_string_literal(src, length);
  return ast;
}
