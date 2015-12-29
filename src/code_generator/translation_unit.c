#include "code_generator.h"
#include "ast/external_definitions_impl.h"
#include "stdstring.h"
#include "ast/is_method.h"
#include "ast/get_method.h"
#include "ast/ast_impl.h"

LLVMTypeRef get_function_type(AstFunctionDefinitionRef function_definition) {
  LLVMTypeRef return_type = get_type(function_definition->declaration_specifier_list);
  TypeVectorRef parameter_types = get_parameter_types(function_definition->declarator);
  return LLVMFunctionType(
      return_type,
      TypeVectorFunc(data)(parameter_types),
      TypeVectorFunc(size)(parameter_types),
      false);
}

void define_function(LLVMModuleRef module, LLVMBuilderRef builder,
    AstFunctionDefinitionRef function_definition) {
  StringRef name = get_name(function_definition->declarator);
  LLVMTypeRef type = get_function_type(function_definition);
  LLVMValueRef func = LLVMAddFunction(module, string_data(name), type);
  LLVMBasicBlockRef entry = LLVMAppendBasicBlock(func, "entry");
  VariableSetRef variable_set = VariableSetFunc(ctor)(NULL);
  LLVMPositionBuilderAtEnd(builder, entry);
  build_block(module, builder, variable_set, function_definition->compound_statement);
}

void translation_unit(LLVMModuleRef module, AstTranslationUnitRef translation_unit) {
  AstVectorRef vector = translation_unit->external_declaration_vector;
  LLVMBuilderRef builder = LLVMCreateBuilder();
  int i;
  for (i = 0; i < (int)AST_VECTOR_FUNC(size)(vector); ++i) {
    AstRef external_declaration = AST_VECTOR_FUNC(at)(vector, i);
    if (ast_is_function_definition(external_declaration)) {
      define_function(module, builder, ast_get_function_definition(external_declaration));
    } else {
      /* declaration(ast_get_declaration(external_declaration)); */
    }
  }
}
