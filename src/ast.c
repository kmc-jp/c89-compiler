#include "ast.h"
#include "ast_pool.h"
#include "ast/token.h"

struct Ast {
  enum AstTag tag;
  union AstData {
    IdentifierRef identifier;
    IntegerConstantRef integer_constant;
    void* dummy;
  } data;
};

static AstRef ast_ctor(void) {
  AstRef ast = ast_palloc(struct Ast, 1);
  ast->tag = AST_TAG_ENUM_END;
  ast->data.dummy = NULL;
  return ast;
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
