#include "token.h"
#include <assert.h>
#include "../ast_pool.h"
#include "../stdstring.h"

struct Identifier {
  StringRef string;
};

IdentifierRef make_identifier(const char* src, size_t length) {
  IdentifierRef self = NULL;
  assert(src);
  self = ast_palloc(struct Identifier, 1);
  self->string = ast_make_string(src, length);
  return self;
}
