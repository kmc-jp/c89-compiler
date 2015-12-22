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
  AstRef struct_or_union_specifier;
};

struct AstStructOrUnionDefinition {
  AstRef struct_or_union;
  AstRef identifier;
  AstRef struct_declaration_list;
};

struct AstStructOrUnionDeclaration {
  AstRef struct_or_union;
  AstRef identifier;
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
  AstRef struct_declarator;
};

struct AstBitFieldDeclarator {
  AstRef declarator;
  AstRef constant_expression;
};

struct AstEnumSpecifier {
  AstRef enum_specifier;
};

struct AstEnumDefinition {
  AstRef identifier;
  AstRef enumerator_list;
};

struct AstEnumDeclaration {
  AstRef identifier;
};

struct AstEnumeratorList {
  AstRef enumerator_list;
};

struct AstEnumerator {
  AstRef enumeration_constant;
  AstRef constant_expression;
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
  if (ast_is_token(type_specifier) ||
      ast_is_struct_or_union_specifier(type_specifier) ||
      ast_is_enum_specifier(type_specifier) ||
      ast_is_typedef_name(type_specifier)) {
    AstTypeSpecifierRef data = ast_palloc(struct AstTypeSpecifier);
    data->type_specifier = type_specifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_TYPE_SPECIFIER;
    self->data.type_specifier = data;
  }
  return self;
}

AstRef ast_make_struct_or_union_specifier(AstRef struct_or_union_specifier) {
  AstRef self = NULL;
  if (ast_is_struct_or_union_definition(struct_or_union_specifier) ||
      ast_is_struct_or_union_declaration(struct_or_union_specifier)) {
    AstStructOrUnionSpecifierRef data = ast_palloc(struct AstStructOrUnionSpecifier);
    data->struct_or_union_specifier = struct_or_union_specifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_OR_UNION_SPECIFIER;
    self->data.struct_or_union_specifier = data;
  }
  return self;
}

AstRef ast_make_struct_or_union_definition(AstRef struct_or_union,
    AstRef identifier, AstRef struct_declaration_list) {
  AstRef self = NULL;
  if (ast_is_struct_or_union(struct_or_union) &&
      (identifier == NULL ||
       ast_is_identifier(identifier)) &&
      ast_is_struct_declaration_list(struct_declaration_list)) {
    AstStructOrUnionDefinitionRef data = ast_palloc(struct AstStructOrUnionDefinition);
    data->struct_or_union = struct_or_union;
    data->identifier = identifier;
    data->struct_declaration_list = struct_declaration_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_OR_UNION_DEFINITION;
    self->data.struct_or_union_definition = data;
  }
  return self;
}

AstRef ast_make_struct_or_union_declaration(AstRef struct_or_union,
    AstRef identifier) {
  AstRef self = NULL;
  if (ast_is_struct_or_union(struct_or_union) &&
      ast_is_identifier(identifier)) {
    AstStructOrUnionDeclarationRef data = ast_palloc(struct AstStructOrUnionDeclaration);
    data->struct_or_union = struct_or_union;
    data->identifier = identifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_OR_UNION_DECLARATION;
    self->data.struct_or_union_declaration = data;
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

AstRef ast_make_struct_declarator(AstRef struct_declarator) {
  AstRef self = NULL;
  if (ast_is_declarator(struct_declarator) ||
      ast_is_bit_field_declarator(struct_declarator)) {
    AstStructDeclaratorRef data = ast_palloc(struct AstStructDeclarator);
    data->struct_declarator = struct_declarator;
    self = ast_palloc(struct Ast);
    self->tag = AST_STRUCT_DECLARATOR;
    self->data.struct_declarator = data;
  }
  return self;
}

AstRef ast_make_bit_field_declarator(AstRef declarator,
    AstRef constant_expression) {
  AstRef self = NULL;
  if ((declarator == NULL || ast_is_declarator(declarator)) &&
       ast_is_constant_expression(constant_expression)) {
    AstBitFieldDeclaratorRef data = ast_palloc(struct AstBitFieldDeclarator);
    data->declarator = declarator;
    data->constant_expression = constant_expression;
    self = ast_palloc(struct Ast);
    self->tag = AST_BIT_FIELD_DECLARATOR;
    self->data.bit_field_declarator = data;
  }
  return self;
}

AstRef ast_make_enum_specifier(AstRef enum_specifier) {
  AstRef self = NULL;
  if (ast_is_enum_definition(enum_specifier) ||
      ast_is_enum_declaration(enum_specifier)) {
    AstEnumSpecifierRef data = ast_palloc(struct AstEnumSpecifier);
    data->enum_specifier = enum_specifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_ENUM_SPECIFIER;
    self->data.enum_specifier = data;
  }
  return self;
}

AstRef ast_make_enum_definition(AstRef identifier, AstRef enumerator_list) {
  AstRef self = NULL;
  if ((identifier == NULL || ast_is_identifier(identifier)) &&
       ast_is_enumerator_list(enumerator_list)) {
    AstEnumDefinitionRef data = ast_palloc(struct AstEnumDefinition);
    data->identifier = identifier;
    data->enumerator_list = enumerator_list;
    self = ast_palloc(struct Ast);
    self->tag = AST_ENUM_DEFINITION;
    self->data.enum_definition = data;
  }
  return self;
}

AstRef ast_make_enum_declaration(AstRef identifier) {
  AstRef self = NULL;
  if (ast_is_identifier(identifier)) {
    AstEnumDeclarationRef data = ast_palloc(struct AstEnumDeclaration);
    data->identifier = identifier;
    self = ast_palloc(struct Ast);
    self->tag = AST_ENUM_DECLARATION;
    self->data.enum_declaration = data;
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
