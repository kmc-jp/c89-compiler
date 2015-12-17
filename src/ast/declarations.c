#include "declarations.h"
#include "ast_impl.h"
#include "is_method.h"
#include "pool.h"

struct AstDeclaration {
};

struct AstDeclarationSpecifiers {
};

struct AstInitDeclaratorList {
};

struct AstInitDeclarator {
};

struct AstStorageClassSpecifier {
};

struct AstTypeSpecifier {
  AstRef type_specifier;
};

struct AstStructOrUnionSpecifier {
};

struct AstStructOrUnion {
};

struct AstStructDeclarationList {
};

struct AstStructDeclaration {
};

struct AstSpecifierQualifierList {
};

struct AstStructDeclaratorList {
};

struct AstStructDeclarator {
};

struct AstEnumSpecifier {
};

struct AstEnumeratorList {
};

struct AstEnumerator {
};

struct AstTypeQualifier {
};

struct AstDeclarator {
};

struct AstDirectDeclarator {
};

struct AstPointer {
};

struct AstTypeQualifierList {
};

struct AstParameterTypeList {
};

struct AstParameterList {
};

struct AstParameterDeclaration {
};

struct AstIdentifierList {
};

struct AstTypeName {
};

struct AstAbstractDeclarator {
};

struct AstDirectAbstractDeclarator {
};

struct AstTypedefName {
};

struct AstInitializer {
};

struct AstInitializerList {
};

AstRef ast_make_type_specifier(AstRef type_specifier) {
  AstRef self = NULL;
  if (ast_is_token(type_specifier)) {
    AstTypeSpecifierRef data = ast_palloc(struct AstTypeSpecifier);
    data->type_specifier = type_specifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_TYPE_SPECIFIER;
    self->data.type_specifier = data;
  }
  return self;
}
