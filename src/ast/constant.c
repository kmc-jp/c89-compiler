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

EnumerationConstantRef make_enumeration_constant(AstRef identifier) {
  EnumerationConstantRef self = NULL;
  IdentifierRef data = get_identifier(identifier);
  if (data) {
    self = ast_palloc(struct EnumerationConstant, 1);
    self->identifier = data;
  }
  return self;
}
