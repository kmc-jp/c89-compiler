#include "declarations.h"
#include "ast_impl.h"
#include "is_method.h"
#include "pool.h"

struct AstDeclaration {
  AstRef declaration_specifier_list;
  AstRef init_declarator_list;
};

struct AstDeclarationSpecifierList {
  AstRef declaration_specifier;
  AstRef declaration_specifier_list;
};

struct AstDeclarationSpecifier {
  AstRef declaration_specifier;
};

struct AstInitDeclaratorList {
};

struct AstInitDeclarator {
};

struct AstStorageClassSpecifier {
};

struct AstTypeSpecifier {
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

AstRef ast_make_declaration(AstRef declaration_specifier_list, AstRef init_declarator_list) {
  AstRef self = NULL;
  if ((ast_is_declaration_specifier_list(declaration_specifier_list)) &&
      (init_declarator_list == NULL || ast_is_init_declarator_list(init_declarator_list))) {
    AstDeclarationRef data = ast_palloc(struct AstDeclaration);
    data->declaration_specifier_list = declaration_specifier_list;
    data->init_declarator_list = init_declarator_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_DECLARATION;
    self->data.declaration = data;
  }
  return self;
}

AstRef ast_make_declaration_specifier_list(AstRef declaration_specifier,
    AstRef declaration_specifier_list) {
  AstRef self = NULL;
  if (ast_is_declaration_specifier(declaration_specifier) &&
      (declaration_specifier_list == NULL ||
       ast_is_declaration_specifier_list(declaration_specifier_list))) {
    AstDeclarationSpecifierListRef data = ast_palloc(struct AstDeclarationSpecifierList);
    data->declaration_specifier = declaration_specifier;
    data->declaration_specifier_list = declaration_specifier_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_DECLARATION_SPECIFIER_LIST;
    self->data.declaration_specifier_list = data;
  }
  return self;
}

AstRef ast_make_declaration_specifier(AstRef declaration_specifier) {
  AstRef self = NULL;
  if (ast_is_storage_class_specifier(declaration_specifier) ||
      ast_is_type_specifier(declaration_specifier) ||
      ast_is_type_qualifier(declaration_specifier)) {
    AstDeclarationSpecifierRef data = ast_palloc(struct AstDeclarationSpecifier);
    data->declaration_specifier = declaration_specifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_DECLARATION_SPECIFIER;
    self->data.declaration_specifier = data;
  }
  return self;
}
