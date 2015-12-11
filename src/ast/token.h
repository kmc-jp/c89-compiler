#ifndef KMC_C89_COMPILER_TOKEN_H
#define KMC_C89_COMPILER_TOKEN_H

#include <stddef.h>

typedef struct Identifier* IdentifierRef;
typedef struct IntegerConstant* IntegerConstantRef;
typedef struct FloatingConstant* FloatingConstantRef;

IdentifierRef make_identifier(const char* src, size_t length);
IntegerConstantRef make_integer_constant(const char* src, size_t length);
FloatingConstantRef make_floating_constant(const char* src, size_t length);

#endif  /* KMC_C89_COMPILER_TOKEN_H */
