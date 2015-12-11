#ifndef KMC_C89_COMPILER_TOKEN_H
#define KMC_C89_COMPILER_TOKEN_H

#include <stddef.h>

typedef struct Identifier* IdentifierRef;

IdentifierRef make_identifier(const char* src, size_t length);

#endif  /* KMC_C89_COMPILER_TOKEN_H */
