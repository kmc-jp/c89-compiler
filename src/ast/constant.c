#include "constant.h"
#include <assert.h>
#include "../ast_method.h"
#include "ast_pool.h"

struct Identifier {
  StringRef string;
};

struct IntegerConstant {
  StringRef string;
};

struct FloatingConstant {
  StringRef string;
};

struct CharacterConstant {
  StringRef string;
};

struct StringLiteral {
  StringRef string;
};

struct Constant {
  AstRef constant;
};

struct EnumerationConstant {
  IdentifierRef identifier;
};

IdentifierRef make_identifier(const char* src, size_t length) {
  IdentifierRef self = NULL;
  assert(src);
  self = ast_palloc(struct Identifier, 1);
  self->string = ast_make_string(src, length);
  return self;
}

IntegerConstantRef make_integer_constant(const char* src, size_t length) {
  IntegerConstantRef self = NULL;
  assert(src);
  self = ast_palloc(struct IntegerConstant, 1);
  self->string = ast_make_string(src, length);
  return self;
}

FloatingConstantRef make_floating_constant(const char* src, size_t length) {
  FloatingConstantRef self = NULL;
  assert(src);
  self = ast_palloc(struct FloatingConstant, 1);
  self->string = ast_make_string(src, length);
  return self;
}

CharacterConstantRef make_character_constant(const char* src, size_t length) {
  CharacterConstantRef self = NULL;
  assert(src);
  self = ast_palloc(struct CharacterConstant, 1);
  self->string = ast_make_string(src, length);
  return self;
}

StringLiteralRef make_string_literal(const char* src, size_t length) {
  StringLiteralRef self = NULL;
  assert(src);
  self = ast_palloc(struct StringLiteral, 1);
  self->string = ast_make_string(src, length);
  return self;
}

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
