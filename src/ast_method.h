#ifndef KMC_C89_COMPILER_AST_METHOD_H
#define KMC_C89_COMPILER_AST_METHOD_H

#include "ast/is_method.h"
#include "ast/get_method.h"
#include "ast/lexical_elements.h"
#include "ast/expressions.h"
#include "ast/declarations.h"
#include "ast/statements.h"
#include "ast/external_definitions.h"
#include "ast/ast_string.h"
#include "ast/ast_vector.h"

#define AST_ERROR(lhs, rhs) \
  do { \
    yyerror(lhs " : " rhs); \
    YYERROR; \
  } while (false)

void ast_initialize_pool(size_t size);
void ast_finalize_pool(void);

#endif  /* KMC_C89_COMPILER_AST_METHOD_H */
