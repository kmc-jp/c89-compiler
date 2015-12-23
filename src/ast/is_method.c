#include "is_method.h"
#include <assert.h>
#include "ast_impl.h"

#define DEFINE_AST_IS_METHOD(lower, upper) \
  bool ast_is_ ## lower(AstRef ast) { \
    assert(ast); \
    return ast->tag == AST_ ## upper; \
  }

DEFINE_AST_IS_METHOD(identifier, IDENTIFIER)
DEFINE_AST_IS_METHOD(constant, CONSTANT)
DEFINE_AST_IS_METHOD(floating_constant, FLOATING_CONSTANT)
DEFINE_AST_IS_METHOD(integer_constant, INTEGER_CONSTANT)
DEFINE_AST_IS_METHOD(enumeration_constant, ENUMERATION_CONSTANT)
DEFINE_AST_IS_METHOD(character_constant, CHARACTER_CONSTANT)
DEFINE_AST_IS_METHOD(string_literal, STRING_LITERAL)
DEFINE_AST_IS_METHOD(primary_expression, PRIMARY_EXPRESSION)
DEFINE_AST_IS_METHOD(postfix_expression, POSTFIX_EXPRESSION)
DEFINE_AST_IS_METHOD(argument_expression_list, ARGUMENT_EXPRESSION_LIST)
DEFINE_AST_IS_METHOD(unary_expression, UNARY_EXPRESSION)
DEFINE_AST_IS_METHOD(unary_operator, UNARY_OPERATOR)
DEFINE_AST_IS_METHOD(cast_expression, CAST_EXPRESSION)
DEFINE_AST_IS_METHOD(multiplicative_expression, MULTIPLICATIVE_EXPRESSION)
DEFINE_AST_IS_METHOD(additive_expression, ADDITIVE_EXPRESSION)
DEFINE_AST_IS_METHOD(shift_expression, SHIFT_EXPRESSION)
DEFINE_AST_IS_METHOD(relational_expression, RELATIONAL_EXPRESSION)
DEFINE_AST_IS_METHOD(equality_expression, EQUALITY_EXPRESSION)
DEFINE_AST_IS_METHOD(and_expression, AND_EXPRESSION)
DEFINE_AST_IS_METHOD(exclusive_or_expression, EXCLUSIVE_OR_EXPRESSION)
DEFINE_AST_IS_METHOD(inclusive_or_expression, INCLUSIVE_OR_EXPRESSION)
DEFINE_AST_IS_METHOD(logical_and_expression, LOGICAL_AND_EXPRESSION)
DEFINE_AST_IS_METHOD(logical_or_expression, LOGICAL_OR_EXPRESSION)
DEFINE_AST_IS_METHOD(conditional_expression, CONDITIONAL_EXPRESSION)
DEFINE_AST_IS_METHOD(assignment_expression, ASSIGNMENT_EXPRESSION)
DEFINE_AST_IS_METHOD(assignment_operator, ASSIGNMENT_OPERATOR)
DEFINE_AST_IS_METHOD(expression, EXPRESSION)
DEFINE_AST_IS_METHOD(constant_expression, CONSTANT_EXPRESSION)
DEFINE_AST_IS_METHOD(declaration, DECLARATION)
DEFINE_AST_IS_METHOD(declaration_specifiers, DECLARATION_SPECIFIERS)
DEFINE_AST_IS_METHOD(init_declarator_list, INIT_DECLARATOR_LIST)
DEFINE_AST_IS_METHOD(init_declarator, INIT_DECLARATOR)
DEFINE_AST_IS_METHOD(storage_class_specifier, STORAGE_CLASS_SPECIFIER)
DEFINE_AST_IS_METHOD(type_specifier, TYPE_SPECIFIER)
DEFINE_AST_IS_METHOD(struct_or_union_specifier, STRUCT_OR_UNION_SPECIFIER)
DEFINE_AST_IS_METHOD(struct_or_union_definition, STRUCT_OR_UNION_DEFINITION)
DEFINE_AST_IS_METHOD(struct_or_union_declaration, STRUCT_OR_UNION_DECLARATION)
DEFINE_AST_IS_METHOD(struct_or_union, STRUCT_OR_UNION)
DEFINE_AST_IS_METHOD(struct_declaration_list, STRUCT_DECLARATION_LIST)
DEFINE_AST_IS_METHOD(struct_declaration, STRUCT_DECLARATION)
DEFINE_AST_IS_METHOD(specifier_qualifier_list, SPECIFIER_QUALIFIER_LIST)
DEFINE_AST_IS_METHOD(specifier_qualifier, SPECIFIER_QUALIFIER)
DEFINE_AST_IS_METHOD(struct_declarator_list, STRUCT_DECLARATOR_LIST)
DEFINE_AST_IS_METHOD(struct_declarator, STRUCT_DECLARATOR)
DEFINE_AST_IS_METHOD(bit_field_declarator, BIT_FIELD_DECLARATOR)
DEFINE_AST_IS_METHOD(enum_specifier, ENUM_SPECIFIER)
DEFINE_AST_IS_METHOD(enum_definition, ENUM_DEFINITION)
DEFINE_AST_IS_METHOD(enum_declaration, ENUM_DECLARATION)
DEFINE_AST_IS_METHOD(enumerator_list, ENUMERATOR_LIST)
DEFINE_AST_IS_METHOD(enumerator, ENUMERATOR)
DEFINE_AST_IS_METHOD(type_qualifier, TYPE_QUALIFIER)
DEFINE_AST_IS_METHOD(declarator, DECLARATOR)
DEFINE_AST_IS_METHOD(direct_declarator, DIRECT_DECLARATOR)
DEFINE_AST_IS_METHOD(pointer, POINTER)
DEFINE_AST_IS_METHOD(type_qualifier_list, TYPE_QUALIFIER_LIST)
DEFINE_AST_IS_METHOD(parameter_type_list, PARAMETER_TYPE_LIST)
DEFINE_AST_IS_METHOD(parameter_list, PARAMETER_LIST)
DEFINE_AST_IS_METHOD(parameter_declaration, PARAMETER_DECLARATION)
DEFINE_AST_IS_METHOD(identifier_list, IDENTIFIER_LIST)
DEFINE_AST_IS_METHOD(type_name, TYPE_NAME)
DEFINE_AST_IS_METHOD(abstract_declarator, ABSTRACT_DECLARATOR)
DEFINE_AST_IS_METHOD(direct_abstract_declarator, DIRECT_ABSTRACT_DECLARATOR)
DEFINE_AST_IS_METHOD(typedef_name, TYPEDEF_NAME)
DEFINE_AST_IS_METHOD(initializer, INITIALIZER)
DEFINE_AST_IS_METHOD(initializer_list, INITIALIZER_LIST)
DEFINE_AST_IS_METHOD(statement, STATEMENT)
DEFINE_AST_IS_METHOD(labeled_statement, LABELED_STATEMENT)
DEFINE_AST_IS_METHOD(compound_statement, COMPOUND_STATEMENT)
DEFINE_AST_IS_METHOD(declaration_list, DECLARATION_LIST)
DEFINE_AST_IS_METHOD(statement_list, STATEMENT_LIST)
DEFINE_AST_IS_METHOD(expression_statement, EXPRESSION_STATEMENT)
DEFINE_AST_IS_METHOD(selection_statement, SELECTION_STATEMENT)
DEFINE_AST_IS_METHOD(iteration_statement, ITERATION_STATEMENT)
DEFINE_AST_IS_METHOD(jump_statement, JUMP_STATEMENT)
DEFINE_AST_IS_METHOD(translation_unit, TRANSLATION_UNIT)
DEFINE_AST_IS_METHOD(external_declaration, EXTERNAL_DECLARATION)
DEFINE_AST_IS_METHOD(function_definition, FUNCTION_DEFINITION)
DEFINE_AST_IS_METHOD(vector, VECTOR)
DEFINE_AST_IS_METHOD(token, TOKEN)
