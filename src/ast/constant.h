#ifndef KMC_C89_COMPILER_CONSTANT_H
#define KMC_C89_COMPILER_CONSTANT_H

#include <stddef.h>
#include "../ast.h"

typedef struct Identifier* IdentifierRef;
typedef struct IntegerConstant* IntegerConstantRef;
typedef struct FloatingConstant* FloatingConstantRef;
typedef struct CharacterConstant* CharacterConstantRef;
typedef struct StringLiteral* StringLiteralRef;
typedef struct Constant* ConstantRef;
typedef struct EnumerationConstant* EnumerationConstantRef;

IdentifierRef make_identifier(const char* src, size_t length);
IntegerConstantRef make_integer_constant(const char* src, size_t length);
FloatingConstantRef make_floating_constant(const char* src, size_t length);
CharacterConstantRef make_character_constant(const char* src, size_t length);
StringLiteralRef make_string_literal(const char* src, size_t length);
ConstantRef make_constant(AstRef constant);
EnumerationConstantRef make_enumeration_constant(AstRef identifier);

#endif  /* KMC_C89_COMPILER_CONSTANT_H */
