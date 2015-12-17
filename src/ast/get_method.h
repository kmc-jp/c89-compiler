#ifndef KMC_C89_COMPILER_AST_GET_METHOD_H
#define KMC_C89_COMPILER_AST_GET_METHOD_H

#include "ast_impl.h"

AstIdentifierRef ast_get_identifier(AstRef ast);
AstConstantRef ast_get_constant(AstRef ast);
AstFloatingConstantRef ast_get_floating_constant(AstRef ast);
AstIntegerConstantRef ast_get_integer_constant(AstRef ast);
AstEnumerationConstantRef ast_get_enumeration_constant(AstRef ast);
AstCharacterConstantRef ast_get_character_constant(AstRef ast);
AstStringLiteralRef ast_get_string_literal(AstRef ast);
AstPrimaryExpressionRef ast_get_primary_expression(AstRef ast);
AstPostfixExpressionRef ast_get_postfix_expression(AstRef ast);
AstArgumentExpressionListRef ast_get_argument_expression_list(AstRef ast);
AstUnaryExpressionRef ast_get_unary_expression(AstRef ast);
AstUnaryOperatorRef ast_get_unary_operator(AstRef ast);
AstCastExpressionRef ast_get_cast_expression(AstRef ast);
AstMultiplicativeExpressionRef ast_get_multiplicative_expression(AstRef ast);
AstAdditiveExpressionRef ast_get_additive_expression(AstRef ast);
AstShiftExpressionRef ast_get_shift_expression(AstRef ast);
AstRelationalExpressionRef ast_get_relational_expression(AstRef ast);
AstEqualityExpressionRef ast_get_equality_expression(AstRef ast);
AstAndExpressionRef ast_get_and_expression(AstRef ast);
AstExclusiveOrExpressionRef ast_get_exclusive_or_expression(AstRef ast);
AstInclusiveOrExpressionRef ast_get_inclusive_or_expression(AstRef ast);
AstLogicalAndExpressionRef ast_get_logical_and_expression(AstRef ast);
AstLogicalOrExpressionRef ast_get_logical_or_expression(AstRef ast);
AstConditionalExpressionRef ast_get_conditional_expression(AstRef ast);
AstAssignmentExpressionRef ast_get_assignment_expression(AstRef ast);
AstAssignmentOperatorRef ast_get_assignment_operator(AstRef ast);
AstExpressionRef ast_get_expression(AstRef ast);
AstConstantExpressionRef ast_get_constant_expression(AstRef ast);
AstDeclarationRef ast_get_declaration(AstRef ast);
AstDeclarationSpecifierListRef ast_get_declaration_specifier_list(AstRef ast);
AstDeclarationSpecifierRef ast_get_declaration_specifier(AstRef ast);
AstInitDeclaratorListRef ast_get_init_declarator_list(AstRef ast);
AstInitDeclaratorRef ast_get_init_declarator(AstRef ast);
AstStorageClassSpecifierRef ast_get_storage_class_specifier(AstRef ast);
AstTypeSpecifierRef ast_get_type_specifier(AstRef ast);
AstStructOrUnionSpecifierRef ast_get_struct_or_union_specifier(AstRef ast);
AstStructOrUnionDefinitionRef ast_get_struct_or_union_definition(AstRef ast);
AstStructOrUnionDeclarationRef ast_get_struct_or_union_declaration(AstRef ast);
AstStructOrUnionRef ast_get_struct_or_union(AstRef ast);
AstStructDeclarationListRef ast_get_struct_declaration_list(AstRef ast);
AstStructDeclarationRef ast_get_struct_declaration(AstRef ast);
AstSpecifierQualifierListRef ast_get_specifier_qualifier_list(AstRef ast);
AstSpecifierQualifierRef ast_get_specifier_qualifier(AstRef ast);
AstStructDeclaratorListRef ast_get_struct_declarator_list(AstRef ast);
AstStructDeclaratorRef ast_get_struct_declarator(AstRef ast);
AstEnumSpecifierRef ast_get_enum_specifier(AstRef ast);
AstEnumeratorListRef ast_get_enumerator_list(AstRef ast);
AstEnumeratorRef ast_get_enumerator(AstRef ast);
AstTypeQualifierRef ast_get_type_qualifier(AstRef ast);
AstDeclaratorRef ast_get_declarator(AstRef ast);
AstDirectDeclaratorRef ast_get_direct_declarator(AstRef ast);
AstArrayTypeDeclaratorRef ast_get_array_type_declarator(AstRef ast);
AstFunctionTypeDeclaratorRef ast_get_function_type_declarator(AstRef ast);
AstPointerRef ast_get_pointer(AstRef ast);
AstTypeQualifierListRef ast_get_type_qualifier_list(AstRef ast);
AstParameterTypeListRef ast_get_parameter_type_list(AstRef ast);
AstParameterListRef ast_get_parameter_list(AstRef ast);
AstParameterDeclarationRef ast_get_parameter_declaration(AstRef ast);
AstIdentifierListRef ast_get_identifier_list(AstRef ast);
AstTypeNameRef ast_get_type_name(AstRef ast);
AstAbstractDeclaratorRef ast_get_abstract_declarator(AstRef ast);
AstDirectAbstractDeclaratorRef ast_get_direct_abstract_declarator(AstRef ast);
AstTypedefNameRef ast_get_typedef_name(AstRef ast);
AstInitializerRef ast_get_initializer(AstRef ast);
AstInitializerListRef ast_get_initializer_list(AstRef ast);
AstStatementRef ast_get_statement(AstRef ast);
AstLabeledStatementRef ast_get_labeled_statement(AstRef ast);
AstCompoundStatementRef ast_get_compound_statement(AstRef ast);
AstDeclarationListRef ast_get_declaration_list(AstRef ast);
AstStatementListRef ast_get_statement_list(AstRef ast);
AstExpressionStatementRef ast_get_expression_statement(AstRef ast);
AstSelectionStatementRef ast_get_selection_statement(AstRef ast);
AstIterationStatementRef ast_get_iteration_statement(AstRef ast);
AstJumpStatementRef ast_get_jump_statement(AstRef ast);
AstTranslationUnitRef ast_get_translation_unit(AstRef ast);
AstExternalDeclarationRef ast_get_external_declaration(AstRef ast);
AstFunctionDefinitionRef ast_get_function_definition(AstRef ast);

AstVectorRef ast_get_vector(AstRef ast);
AstTokenRef ast_get_token(AstRef ast);

#endif  /* KMC_C89_COMPILER_AST_GET_METHOD_H */
