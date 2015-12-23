#include "expressions.h"
#include "ast_impl.h"
#include "is_method.h"
#include "pool.h"

struct AstPrimaryExpression {
};

struct AstPostfixExpression {
  AstRef postfix;
};

struct AstArraySubscriptExpression {
  AstRef array;
  AstRef subscript;
};

struct AstFunctionCallExpression {
  AstRef function;
  AstRef argument_list;
};

struct AstMemberAccessExpression {
  AstRef object;
  AstRef member;
};

struct AstMemberAccessThroughPointerExpression {
  AstRef object;
  AstRef member;
};

struct AstPostfixIncrementExpression {
  AstRef postfix;
};

struct AstPostfixDecrementExpression {
};

struct AstArgumentExpressionList {
};

struct AstUnaryExpression {
};

struct AstPrefixIncrementExpression {
};

struct AstPrefixDecrementExpression {
};

struct AstAddressOfExpression {
};

struct AstPointerDereferenceExpression {
};

struct AstUnaryPlusExpression {
};

struct AstUnaryMinusExpression {
};

struct AstBitwiseNotExpression {
};

struct AstLogicalNotExpression {
};

struct AstSizeofExpression {
};

struct AstSizeofTypeExpression {
};

struct AstCastExpression {
};

struct AstTypeCastExpression {
};

struct AstMultiplicativeExpression {
};

struct AstProductExpression {
};

struct AstDivisionExpression {
};

struct AstModuloExpression {
};

struct AstAdditiveExpression {
};

struct AstAdditionExpression {
};

struct AstSubtractionExpression {
};

struct AstShiftExpression {
};

struct AstLeftShiftExpression {
};

struct AstRightShiftExpression {
};

struct AstRelationalExpression {
};

struct AstLessThanExpression {
};

struct AstGreaterThanExpression {
};

struct AstLessThanOrEqualToExpression {
};

struct AstGreaterThanOrEqualToExpression {
};

struct AstEqualityExpression {
};

struct AstEqualToExpression {
};

struct AstNotEqualToExpression {
};

struct AstBitwiseAndExpression {
};

struct AstBitwiseAndOperatorExpression {
};

struct AstBitwiseXorExpression {
};

struct AstBitwiseXorOperatorExpression {
};

struct AstBitwiseOrExpression {
};

struct AstBitwiseOrOperatorExpression {
};

struct AstLogicalAndExpression {
};

struct AstLogicalAndOperatorExpression {
};

struct AstLogicalOrExpression {
};

struct AstLogicalOrOperatorExpression {
};

struct AstConditionalExpression {
};

struct AstConditionalOperatorExpression {
};

struct AstAssignmentExpression {
};

struct AstBasicAssignmentExpression {
};

struct AstMultiplicationAssignmentExpression {
};

struct AstDivisionAssignmentExpression {
};

struct AstModuloAssignmentExpression {
};

struct AstAdditionAssignmentExpression {
};

struct AstSubtractionAssignmentExpression {
};

struct AstLeftShiftAssignmentExpression {
};

struct AstRightShiftAssignmentExpression {
};

struct AstBitwiseAndAssignmentExpression {
};

struct AstBitwiseXorAssignmentExpression {
};

struct AstBitwiseOrAssignmentExpression {
};

struct AstExpression {
};

struct AstCommaExpression {
};

struct AstConstantExpression {
};

AstRef ast_make_postfix_expression(AstRef postfix) {
  AstRef self = NULL;
  if (ast_is_primary_expression(postfix) ||
      ast_is_array_subscript_expression(postfix) ||
      ast_is_function_call_expression(postfix) ||
      ast_is_member_access_expression(postfix) ||
      ast_is_member_access_through_pointer_expression(postfix) ||
      ast_is_postfix_increment_expression(postfix) ||
      ast_is_postfix_decrement_expression(postfix)) {
    AstPostfixExpressionRef data = ast_palloc(struct AstPostfixExpression);
    data->postfix = postfix;
    self = ast_palloc(struct Ast);
    self->tag = AST_POSTFIX_EXPRESSION;
    self->data.postfix_expression = data;
  }
  return self;
}

AstRef ast_make_array_subscript_expression(AstRef array, AstRef subscript) {
  AstRef self = NULL;
  if (ast_is_postfix_expression(array) ||
      ast_is_expression(subscript)) {
    AstArraySubscriptExpressionRef data =
        ast_palloc(struct AstArraySubscriptExpression);
    data->array = array;
    data->subscript = subscript;
    self = ast_palloc(struct Ast);
    self->tag = AST_ARRAY_SUBSCRIPT_EXPRESSION;
    self->data.array_subscript_expression = data;
  }
  return self;
}

AstRef ast_make_function_call_expression(
    AstRef function, AstRef argument_list) {
  AstRef self = NULL;
  if (ast_is_postfix_expression(function) ||
      ast_is_argument_expression_list(argument_list)) {
    AstFunctionCallExpressionRef data =
        ast_palloc(struct AstFunctionCallExpression);
    data->function = function;
    data->argument_list = argument_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_FUNCTION_CALL_EXPRESSION;
    self->data.function_call_expression = data;
  }
  return self;
}

AstRef ast_make_member_access_expression(AstRef object, AstRef member) {
  AstRef self = NULL;
  if (ast_is_postfix_expression(object) ||
      ast_is_identifier(member)) {
    AstMemberAccessExpressionRef data =
        ast_palloc(struct AstMemberAccessExpression);
    data->object = object;
    data->member = member;
    self = ast_palloc(struct Ast);
    self->tag = AST_MEMBER_ACCESS_EXPRESSION;
    self->data.member_access_expression = data;
  }
  return self;
}

AstRef ast_make_member_access_through_pointer_expression(
    AstRef object, AstRef member) {
  AstRef self = NULL;
  if (ast_is_postfix_expression(object) ||
      ast_is_identifier(member)) {
    AstMemberAccessThroughPointerExpressionRef data =
        ast_palloc(struct AstMemberAccessThroughPointerExpression);
    data->object = object;
    data->member = member;
    self = ast_palloc(struct Ast);
    self->tag = AST_MEMBER_ACCESS_THROUGH_POINTER_EXPRESSION;
    self->data.member_access_through_pointer_expression = data;
  }
  return self;
}

AstRef ast_make_postfix_increment_expression(AstRef postfix) {
  AstRef self = NULL;
  if (ast_is_postfix_expression(postfix)) {
    AstPostfixIncrementExpressionRef data =
        ast_palloc(struct AstPostfixIncrementExpression);
    data->postfix = postfix;
    self = ast_palloc(struct Ast);
    self->tag = AST_POSTFIX_INCREMENT_EXPRESSION;
    self->data.postfix_increment_expression = data;
  }
  return self;
}
