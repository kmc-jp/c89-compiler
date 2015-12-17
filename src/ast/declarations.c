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
  AstRef struct_or_union;
  AstRef identifier;
  AstRef struct_declaration_list;
};

struct AstStructOrUnion {
  AstRef struct_or_union;
};

struct AstStructDeclarationList {
  AstRef struct_declaration_list;
};

struct AstStructDeclaration {
  AstRef specifier_qualifier_list;
  AstRef struct_declarator_list;
};

struct AstSpecifierQualifierList {
  AstRef specifier_qualifier;
  AstRef specifier_qualifier_list;
};

struct AstSpecifierQualifier {
  AstRef specifier_qualifier;
};

struct AstStructDeclaratorList {
  AstRef struct_declarator_list;
};

struct AstStructDeclarator {
  AstRef declarator;
  AstRef constant_expression;
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

AstRef ast_make_struct_or_union_specifier(AstRef struct_or_union,
    AstRef identifier, AstRef struct_declaration_list) {
  AstRef self = NULL;
  int is_null_or_identifier = identifier == NULL ||
    ast_is_identifier(identifier);
  int is_null_or_struct_declaration_list = struct_declaration_list == NULL ||
    ast_is_struct_declaration_list(struct_declaration_list);
  if (ast_is_struct_or_union(struct_or_union) &&
      is_null_or_identifier && is_null_or_struct_declaration_list &&
      (identifier != NULL || struct_declaration_list != NULL)) {
    AstStructOrUnionSpecifierRef data = ast_palloc(struct AstStructOrUnionSpecifier);
    data->struct_or_union = struct_or_union;
    data->identifier = identifier;
    data->struct_declaration_list = struct_declaration_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_OR_UNION_SPECIFIER;
    self->data.struct_or_union_specifier = data;
  }
  return self;
}

AstRef ast_make_struct_or_union(AstRef struct_or_union) {
  AstRef self = NULL;
  if (ast_is_token(struct_or_union)) {
    AstStructOrUnionRef data = ast_palloc(struct AstStructOrUnion);
    data->struct_or_union = struct_or_union;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_OR_UNION;
    self->data.struct_or_union = data;
  }
  return self;
}

AstRef ast_make_struct_declaration_list(AstRef struct_declaration_list) {
  AstRef self = NULL;
  if (ast_is_vector(struct_declaration_list)) {
    AstStructDeclarationListRef data = ast_palloc(struct AstStructDeclarationList);
    data->struct_declaration_list = struct_declaration_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_DECLARATION_LIST;
    self->data.struct_declaration_list = data;
  }
  return self;
}

AstRef ast_make_struct_declaration(AstRef specifier_qualifier_list,
    AstRef struct_declarator_list) {
  AstRef self = NULL;
  if (ast_is_specifier_qualifier_list(specifier_qualifier_list)) {
    AstStructDeclarationRef data = ast_palloc(struct AstStructDeclaration);
    data->specifier_qualifier_list = specifier_qualifier_list;
    data->struct_declarator_list = struct_declarator_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_DECLARATION;
    self->data.struct_declaration = data;
  }
  return self;
}

AstRef ast_make_specifier_qualifier_list(AstRef specifier_qualifier,
    AstRef specifier_qualifier_list) {
  AstRef self = NULL;
  if (ast_is_specifier_qualifier(specifier_qualifier) &&
      (specifier_qualifier_list == NULL ||
       ast_is_specifier_qualifier_list(specifier_qualifier_list))) {
    AstSpecifierQualifierListRef data = ast_palloc(struct AstSpecifierQualifierList);
    data->specifier_qualifier = specifier_qualifier;
    data->specifier_qualifier_list = specifier_qualifier_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_SPECIFIER_QUALIFIER_LIST;
    self->data.specifier_qualifier_list = data;
  }
  return self;
}

AstRef ast_make_specifier_qualifier(AstRef specifier_qualifier) {
  AstRef self = NULL;
  if (ast_is_type_specifier(specifier_qualifier) ||
      ast_is_type_qualifier(specifier_qualifier)) {
    AstSpecifierQualifierRef data = ast_palloc(struct AstSpecifierQualifier);
    data->specifier_qualifier = specifier_qualifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_SPECIFIER_QUALIFIER;
    self->data.specifier_qualifier = data;
  }
  return self;
}

AstRef ast_make_struct_declarator_list(AstRef struct_declarator_list) {
  AstRef self = NULL;
  if (ast_is_vector(struct_declarator_list)) {
    AstStructDeclaratorListRef data = ast_palloc(struct AstStructDeclaratorList);
    data->struct_declarator_list = struct_declarator_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_DECLARATOR_LIST;
    self->data.struct_declarator_list = data;
  }
  return self;
}

AstRef ast_make_struct_declarator(AstRef declarator,
    AstRef constant_expression) {
  AstRef self = NULL;
  if (((declarator == NULL || ast_is_declarator(declarator)) &&
       ast_is_constant_expression(constant_expression)) ||
      (ast_is_declarator(declarator) && constant_expression == NULL)) {
    AstStructDeclaratorRef data = ast_palloc(struct AstStructDeclarator);
    data->declarator = declarator;
    data->constant_expression = constant_expression;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_DECLARATOR;
    self->data.struct_declarator = data;
  }
  return self;
}
