#include "ast.h"
#include "ast_pool.h"
#include "ast/token.h"

struct Ast {
  enum AstTag tag;
  union AstData {
    IdentifierRef identifier;
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
