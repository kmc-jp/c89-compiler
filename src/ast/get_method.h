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
AstArraySubscriptExpressionRef ast_get_array_subscript_expression(AstRef ast);
AstFunctionCallExpressionRef ast_get_function_call_expression(AstRef ast);
AstMemberAccessExpressionRef ast_get_member_access_expression(AstRef ast);
AstMemberAccessThroughPointerExpressionRef ast_get_member_access_through_pointer_expression(AstRef ast);
AstPostfixIncrementExpressionRef ast_get_postfix_increment_expression(AstRef ast);
AstPostfixDecrementExpressionRef ast_get_postfix_decrement_expression(AstRef ast);
AstArgumentExpressionListRef ast_get_argument_expression_list(AstRef ast);
AstUnaryExpressionRef ast_get_unary_expression(AstRef ast);
AstPrefixIncrementExpressionRef ast_get_prefix_increment_expression(AstRef ast);
AstPrefixDecrementExpressionRef ast_get_prefix_decrement_expression(AstRef ast);
AstAddressOfExpressionRef ast_get_address_of_expression(AstRef ast);
AstPointerDereferenceExpressionRef ast_get_pointer_dereference_expression(AstRef ast);
AstUnaryPlusExpressionRef ast_get_unary_plus_expression(AstRef ast);
AstUnaryMinusExpressionRef ast_get_unary_minus_expression(AstRef ast);
AstBitwiseNotExpressionRef ast_get_bitwise_not_expression(AstRef ast);
AstLogicalNotExpressionRef ast_get_logical_not_expression(AstRef ast);
AstSizeofExpressionRef ast_get_sizeof_expression(AstRef ast);
AstSizeofTypeExpressionRef ast_get_sizeof_type_expression(AstRef ast);
AstCastExpressionRef ast_get_cast_expression(AstRef ast);
AstTypeCastExpressionRef ast_get_type_cast_expression(AstRef ast);
AstMultiplicativeExpressionRef ast_get_multiplicative_expression(AstRef ast);
AstProductExpressionRef ast_get_product_expression(AstRef ast);
AstDivisionExpressionRef ast_get_division_expression(AstRef ast);
AstModuloExpressionRef ast_get_modulo_expression(AstRef ast);
AstAdditiveExpressionRef ast_get_additive_expression(AstRef ast);
AstAdditionExpressionRef ast_get_addition_expression(AstRef ast);
AstSubtractionExpressionRef ast_get_subtraction_expression(AstRef ast);
AstShiftExpressionRef ast_get_shift_expression(AstRef ast);
AstLeftShiftExpressionRef ast_get_left_shift_expression(AstRef ast);
AstRightShiftExpressionRef ast_get_right_shift_expression(AstRef ast);
AstRelationalExpressionRef ast_get_relational_expression(AstRef ast);
AstLessThanExpressionRef ast_get_less_than_expression(AstRef ast);
AstGreaterThanExpressionRef ast_get_greater_than_expression(AstRef ast);
AstLessThanOrEqualToExpressionRef ast_get_less_than_or_equal_to_expression(AstRef ast);
AstGreaterThanOrEqualToExpressionRef ast_get_greater_than_or_equal_to_expression(AstRef ast);
AstEqualityExpressionRef ast_get_equality_expression(AstRef ast);
AstEqualToExpressionRef ast_get_equal_to_expression(AstRef ast);
AstNotEqualToExpressionRef ast_get_not_equal_to_expression(AstRef ast);
AstBitwiseAndExpressionRef ast_get_bitwise_and_expression(AstRef ast);
AstBitwiseAndOperatorExpressionRef ast_get_bitwise_and_operator_expression(AstRef ast);
AstBitwiseXorExpressionRef ast_get_bitwise_xor_expression(AstRef ast);
AstBitwiseXorOperatorExpressionRef ast_get_bitwise_xor_operator_expression(AstRef ast);
AstBitwiseOrExpressionRef ast_get_bitwise_or_expression(AstRef ast);
AstBitwiseOrOperatorExpressionRef ast_get_bitwise_or_operator_expression(AstRef ast);
AstLogicalAndExpressionRef ast_get_logical_and_expression(AstRef ast);
AstLogicalAndOperatorExpressionRef ast_get_logical_and_operator_expression(AstRef ast);
AstLogicalOrExpressionRef ast_get_logical_or_expression(AstRef ast);
AstLogicalOrOperatorExpressionRef ast_get_logical_or_operator_expression(AstRef ast);
AstConditionalExpressionRef ast_get_conditional_expression(AstRef ast);
AstConditionalOperatorExpressionRef ast_get_conditional_operator_expression(AstRef ast);
AstAssignmentExpressionRef ast_get_assignment_expression(AstRef ast);
AstBasicAssignmentExpressionRef ast_get_basic_assignment_expression(AstRef ast);
AstMultiplicationAssignmentExpressionRef ast_get_multiplication_assignment_expression(AstRef ast);
AstDivisionAssignmentExpressionRef ast_get_division_assignment_expression(AstRef ast);
AstModuloAssignmentExpressionRef ast_get_modulo_assignment_expression(AstRef ast);
AstAdditionAssignmentExpressionRef ast_get_addition_assignment_expression(AstRef ast);
AstSubtractionAssignmentExpressionRef ast_get_subtraction_assignment_expression(AstRef ast);
AstLeftShiftAssignmentExpressionRef ast_get_left_shift_assignment_expression(AstRef ast);
AstRightShiftAssignmentExpressionRef ast_get_right_shift_assignment_expression(AstRef ast);
AstBitwiseAndAssignmentExpressionRef ast_get_bitwise_and_assignment_expression(AstRef ast);
AstBitwiseXorAssignmentExpressionRef ast_get_bitwise_xor_assignment_expression(AstRef ast);
AstBitwiseOrAssignmentExpressionRef ast_get_bitwise_or_assignment_expression(AstRef ast);
AstExpressionRef ast_get_expression(AstRef ast);
AstCommaExpressionRef ast_get_comma_expression(AstRef ast);
AstConstantExpressionRef ast_get_constant_expression(AstRef ast);
AstDeclarationRef ast_get_declaration(AstRef ast);
AstDeclarationSpecifiersRef ast_get_declaration_specifiers(AstRef ast);
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
AstBitFieldDeclaratorRef ast_get_bit_field_declarator(AstRef ast);
AstEnumSpecifierRef ast_get_enum_specifier(AstRef ast);
AstEnumDefinitionRef ast_get_enum_definition(AstRef ast);
AstEnumDeclarationRef ast_get_enum_declaration(AstRef ast);
AstEnumeratorListRef ast_get_enumerator_list(AstRef ast);
AstEnumeratorRef ast_get_enumerator(AstRef ast);
AstTypeQualifierRef ast_get_type_qualifier(AstRef ast);
AstDeclaratorRef ast_get_declarator(AstRef ast);
AstDirectDeclaratorRef ast_get_direct_declarator(AstRef ast);
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
