#ifndef KMC_C89_COMPILER_AST_EXPRESSION_H
#define KMC_C89_COMPILER_AST_EXPRESSION_H

#include "../ast.h"

AstRef ast_make_primary_expression();
AstRef ast_make_postfix_expression();
AstRef ast_make_array_subscript_expression();
AstRef ast_make_function_call_expression();
AstRef ast_make_member_access_expression();
AstRef ast_make_member_access_through_pointer_expression();
AstRef ast_make_postfix_increment_expression();
AstRef ast_make_postfix_decrement_expression();
AstRef ast_make_argument_expression_list();
AstRef ast_make_unary_expression(AstRef unary);
AstRef ast_make_prefix_increment_expression(AstRef unary);
AstRef ast_make_prefix_decrement_expression(AstRef unary);
AstRef ast_make_address_of_expression(AstRef cast);
AstRef ast_make_pointer_dereference_expression(AstRef cast);
AstRef ast_make_unary_plus_expression(AstRef cast);
AstRef ast_make_unary_minus_expression(AstRef cast);
AstRef ast_make_bitwise_not_expression(AstRef cast);
AstRef ast_make_logical_not_expression(AstRef cast);
AstRef ast_make_sizeof_expression(AstRef unary);
AstRef ast_make_sizeof_type_expression(AstRef type_name);
AstRef ast_make_cast_expression();
AstRef ast_make_type_cast_expression();
AstRef ast_make_multiplicative_expression();
AstRef ast_make_product_expression();
AstRef ast_make_division_expression();
AstRef ast_make_modulo_expression();
AstRef ast_make_additive_expression();
AstRef ast_make_addition_expression();
AstRef ast_make_subtraction_expression();
AstRef ast_make_shift_expression();
AstRef ast_make_left_shift_expression();
AstRef ast_make_right_shift_expression();
AstRef ast_make_relational_expression();
AstRef ast_make_less_than_expression();
AstRef ast_make_greater_than_expression();
AstRef ast_make_less_than_or_equal_to_expression();
AstRef ast_make_greater_than_or_equal_to_expression();
AstRef ast_make_equality_expression();
AstRef ast_make_equal_to_expression();
AstRef ast_make_not_equal_to_expression();
AstRef ast_make_bitwise_and_expression();
AstRef ast_make_bitwise_and_operator_expression();
AstRef ast_make_bitwise_xor_expression();
AstRef ast_make_bitwise_xor_operator_expression();
AstRef ast_make_bitwise_or_expression();
AstRef ast_make_bitwise_or_operator_expression();
AstRef ast_make_logical_and_expression();
AstRef ast_make_logical_and_operator_expression();
AstRef ast_make_logical_or_expression();
AstRef ast_make_logical_or_operator_expression();
AstRef ast_make_conditional_expression();
AstRef ast_make_conditional_operator_expression();
AstRef ast_make_assignment_expression();
AstRef ast_make_basic_assignment_expression();
AstRef ast_make_multiplication_assignment_expression();
AstRef ast_make_division_assignment_expression();
AstRef ast_make_modulo_assignment_expression();
AstRef ast_make_addition_assignment_expression();
AstRef ast_make_subtraction_assignment_expression();
AstRef ast_make_left_shift_assignment_expression();
AstRef ast_make_right_shift_assignment_expression();
AstRef ast_make_bitwise_and_assignment_expression();
AstRef ast_make_bitwise_xor_assignment_expression();
AstRef ast_make_bitwise_or_assignment_expression();
AstRef ast_make_expression();
AstRef ast_make_comma_expression();
AstRef ast_make_constant_expression();

#endif  /* KMC_C89_COMPILER_AST_EXPRESSION_H */
