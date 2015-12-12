#include "constant.h"
#include "../ast_method.h"
#include "ast_pool.h"
#include "token.h"

struct Constant {
  AstRef constant;
};

struct EnumerationConstant {
  IdentifierRef identifier;
};

ConstantRef make_constant(AstRef constant) {
  ConstantRef self = NULL;
  if (get_integer_constant(constant) ||
      get_floating_constant(constant) ||
      get_enumeration_constant(constant) ||
      get_character_constant(constant)) {
    self = ast_palloc(struct Constant, 1);
    self->constant = constant;
  }
  return self;
}

EnumerationConstantRef make_enumeration_constant(AstRef identifier) {
  EnumerationConstantRef self = NULL;
  IdentifierRef data = get_identifier(identifier);
  if (data) {
    self = ast_palloc(struct EnumerationConstant, 1);
    self->identifier = data;
  }
  return self;
}
