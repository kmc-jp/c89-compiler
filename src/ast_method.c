#include "ast_method.h"
#include <assert.h>
#include "ast_impl.h"

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


EnumerationConstantRef get_enumeration_constant(AstRef ast) {
  assert(ast);
  if (ast->tag == AST_ENUMERATION_CONSTANT) {
    return ast->data.enumeration_constant;
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


AstRef make_ast_constant(AstRef constant) {
  AstRef self = NULL;
  ConstantRef data = make_constant(constant);
  if (data) {
    self = ast_ctor();
    self->tag = AST_CONSTANT;
    self->data.constant = data;
  }
  return self;
}

AstRef make_ast_enumeration_constant(AstRef identifier) {
  AstRef self = NULL;
  EnumerationConstantRef data = make_enumeration_constant(identifier);
  if (data) {
    self = ast_ctor();
    self->tag = AST_ENUMERATION_CONSTANT;
    self->data.enumeration_constant = data;
  }
  return self;
}
