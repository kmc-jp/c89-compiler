#include "ast.h"
#include "ast_impl.h"
#include "ast/ast_pool.h"

AstRef ast_ctor(void) {
  AstRef ast = ast_palloc(struct Ast, 1);
  ast->tag = AST_TAG_ENUM_END;
  ast->data.dummy = NULL;
  return ast;
}
