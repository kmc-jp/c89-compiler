#ifndef KMC_C90_COMPILER_CODE_GENERATOR_EXTERNAL_DEFINITIONS_H
#define KMC_C90_COMPILER_CODE_GENERATOR_EXTERNAL_DEFINITIONS_H

#include "ast.h"

void generate_translation_unit(AstTranslationUnitRef translation_unit);

void generate_external_declaration(AstExternalDeclarationRef external_declaration);

#endif  /* KMC_C90_COMPILER_CODE_GENERATOR_EXTERNAL_DEFINITIONS_H */
