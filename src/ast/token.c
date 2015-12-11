#include "token.h"
#include <assert.h>
#include "../ast_pool.h"
#include "../stdstring.h"

struct Identifier {
  StringRef string;
};

struct IntegerConstant {
  StringRef string;
};

struct FloatingConstant {
  StringRef string;
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
