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
  AstRef init_declarator_list;
};

struct AstInitDeclarator {
  AstRef declarator;
  AstRef initializer;
};

struct AstStorageClassSpecifier {
  AstRef storage_class_specifier;
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
  AstRef identifier;
  AstRef enumerator_list;
};

struct AstEnumeratorList {
  AstRef enumerator_list;
};

struct AstEnumerator {
  AstRef enumeration_constant;
  AstRef constant_expression;
};

struct AstTypeQualifier {
  AstRef type_qualifier;
};

struct AstDeclarator {
  AstRef pointer;
  AstRef direct_declarator;
};

struct AstDirectDeclarator {
  AstRef direct_declarator;
};

struct AstArrayTypeDeclarator {
  AstRef direct_declarator;
  AstRef constant_expression;
};

struct AstFunctionTypeDeclarator {
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

AstRef ast_make_init_declarator_list(AstRef init_declarator_list) {
  AstRef self = NULL;
  if (ast_is_vector(init_declarator_list)) {
    AstInitDeclaratorListRef data = ast_palloc(struct AstInitDeclaratorList);
    data->init_declarator_list = init_declarator_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_INIT_DECLARATOR_LIST;
    self->data.init_declarator_list = data;
  }
  return self;
}

AstRef ast_make_init_declarator(AstRef declarator, AstRef initializer) {
  AstRef self = NULL;
  if (ast_is_declarator(declarator) &&
      (initializer == NULL || ast_is_initializer(initializer))) {
    AstInitDeclaratorRef data = ast_palloc(struct AstInitDeclarator);
    data->declarator = declarator;
    data->initializer = initializer;
    self = ast_palloc(struct Ast);
    self->tag = AST_INIT_DECLARATOR;
    self->data.init_declarator = data;
  }
  return self;
}

AstRef ast_make_storage_class_specifier(AstRef storage_class_specifier) {
  AstRef self = NULL;
  if (ast_is_token(storage_class_specifier)) {
    AstStorageClassSpecifierRef data = ast_palloc(struct AstStorageClassSpecifier);
    data->storage_class_specifier = storage_class_specifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_STORAGE_CLASS_SPECIFIER;
    self->data.storage_class_specifier = data;
  }
  return self;
}

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

AstRef ast_make_enum_specifier(AstRef identifier, AstRef enumerator_list) {
  AstRef self = NULL;
  if (((identifier == NULL || ast_is_identifier(identifier)) &&
       ast_is_enumerator_list(enumerator_list)) ||
      (ast_is_identifier(identifier) && enumerator_list == NULL)) {
    AstEnumSpecifierRef data = ast_palloc(struct AstEnumSpecifier);
    data->identifier = identifier;
    data->enumerator_list = enumerator_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_ENUM_SPECIFIER;
    self->data.enum_specifier = data;
  }
  return self;
}

AstRef ast_make_enumerator_list(AstRef enumerator_list) {
  AstRef self = NULL;
  if (ast_is_vector(enumerator_list)) {
    AstEnumeratorListRef data = ast_palloc(struct AstEnumeratorList);
    data->enumerator_list = enumerator_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_ENUMERATOR_LIST;
    self->data.enumerator_list = data;
  }
  return self;
}

AstRef ast_make_enumerator(AstRef enumeration_constant,
    AstRef constant_expression) {
  AstRef self = NULL;
  if (ast_is_identifier(enumeration_constant) &&
      (constant_expression == NULL ||
       ast_is_constant_expression(constant_expression))) {
    AstEnumeratorRef data = ast_palloc(struct AstEnumerator);
    data->enumeration_constant = enumeration_constant;
    data->constant_expression = constant_expression;
    self = ast_palloc(struct Ast);
    self->tag = AST_ENUMERATOR;
    self->data.enumerator = data;
  }
  return self;
}

AstRef ast_make_type_qualifier(AstRef type_qualifier) {
  AstRef self = NULL;
  if (ast_is_token(type_qualifier)) {
    AstTypeQualifierRef data = ast_palloc(struct AstTypeQualifier);
    data->type_qualifier = type_qualifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_TYPE_QUALIFIER;
    self->data.type_qualifier = data;
  }
  return self;
}

AstRef ast_make_declarator(AstRef pointer, AstRef direct_declarator) {
  AstRef self = NULL;
  if ((pointer == NULL || ast_is_pointer(pointer)) &&
      ast_is_direct_declarator(direct_declarator)) {
    AstDeclaratorRef data = ast_palloc(struct AstDeclarator);
    data->pointer = pointer;
    data->direct_declarator = direct_declarator;
    self = ast_palloc(struct Ast);
    self->tag = AST_DECLARATOR;
    self->data.declarator = data;
  }
  return self;
}

AstRef ast_make_direct_declarator(AstRef direct_declarator) {
  AstRef self = NULL;
  if (ast_is_identifier(direct_declarator) ||
      ast_is_declarator(direct_declarator) ||
      ast_is_array_type_declarator(direct_declarator) ||
      ast_is_function_type_declarator(direct_declarator)) {
    AstDirectDeclaratorRef data = ast_palloc(struct AstDirectDeclarator);
    data->direct_declarator = direct_declarator;
    self = ast_palloc(struct Ast);
    self->tag = AST_DIRECT_DECLARATOR;
    self->data.direct_declarator = data;
  }
  return self;
}

AstRef ast_make_array_type_declarator(AstRef direct_declarator,
    AstRef constant_expression) {
  AstRef self = NULL;
  if (ast_is_direct_declarator(direct_declarator) &&
      (constant_expression == NULL ||
       ast_is_constant_expression(constant_expression))) {
    AstArrayTypeDeclaratorRef data = ast_palloc(struct AstArrayTypeDeclarator);
    data->direct_declarator = direct_declarator;
    data->constant_expression = constant_expression;
    self = ast_palloc(struct Ast);
    self->tag = AST_ARRAY_TYPE_DECLARATOR;
    self->data.array_type_declarator = data;
  }
  return self;
}
