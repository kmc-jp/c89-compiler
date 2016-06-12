#include "code_generator/external_definitions.h"
#include <assert.h>
#include "ast/external_definitions_impl.h"
#include "ast/is_method.h"
#include "ast/pool.h"
#include "code_generator/generate.h"
#include "error.h"

void generate_translation_unit(AstTranslationUnitRef translation_unit) {
  assert(translation_unit);
  {
    const AstVectorRef vector = translation_unit->external_declaration_vector;
    const AstRef* const begin = AST_VECTOR_FUNC(begin)(vector);
    const AstRef* const end = AST_VECTOR_FUNC(end)(vector);
    const AstRef* iter = NULL;
    for (iter = begin; iter != end; ++iter) {
      if (ast_is_external_declaration(*iter)) {
        generate_code(*iter);
      } else {
        error("Not translation_unit");
      }
    }
  }
}

void generate_external_declaration(AstExternalDeclarationRef external_declaration) {
  assert(external_declaration);
  {
    const AstRef ast = external_declaration->external_declaration;
    if (ast_is_function_definition(ast) || ast_is_declaration(ast)) {
      generate_code(ast);
    } else {
      error("Not external_declaration");
    }
  }
}
