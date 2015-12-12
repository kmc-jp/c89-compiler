#ifndef KMC_C89_COMPILER_CONSTANT_H
#define KMC_C89_COMPILER_CONSTANT_H

#include "../ast.h"

typedef struct EnumerationConstant* EnumerationConstantRef;

EnumerationConstantRef make_enumeration_constant(AstRef identifier);

#endif  /* KMC_C89_COMPILER_CONSTANT_H */
