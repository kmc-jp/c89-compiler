#include "ast.h"
#include "ast_pool.h"

struct Ast {
  enum AstTag tag;
  union AstData {
    void* dummy;
  } data;
};

static AstRef ast_ctor(void) {
  AstRef ast = ast_palloc(struct Ast, 1);
  ast->tag = AST_TAG_ENUM_END;
  ast->data.dummy = NULL;
  return ast;
}
