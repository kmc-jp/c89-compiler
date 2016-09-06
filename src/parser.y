%code {
#include <stdio.h>
#include "utility.h"

#define AST_ERROR(lhs, rhs) \
  do { \
    yyerror("cannot parse `" lhs "` as `" rhs "`"); \
    YYERROR; \
  } while (false)

void yyerror(const char *);
}

%code provides {
int yylex(void);
void set_yyin_file(const char *filename);
void set_yyin_string(const char *code);
}

%code requires {
#include "sexpr.h"
#define YYSTYPE SexprRef
}

%token IDENTIFIER
%token FLOATING_CONSTANT
%token INTEGER_CONSTANT
%token CHARACTER_CONSTANT
%token STRING_LITERAL
%token ARROW "->"
%token INCREMENT "++"
%token DECREMENT "--"
%token LEFT_SHIFT "<<"
%token RIGHT_SHIFT ">>"
%token EQUAL "=="
%token NOT_EQUAL "!="
%token LESS "<"
%token GREATER ">"
%token LESS_EQUAL "<="
%token GREATER_EQUAL ">="
%token AND "&&"
%token OR "||"
%token ADD_ASSIGN "+="
%token SUB_ASSIGN "-="
%token MUL_ASSIGN "*="
%token DIV_ASSIGN "/="
%token MOD_ASSIGN "%="
%token LEFT_SHIFT_ASSIGN "<<="
%token RIGHT_SHIFT_ASSIGN ">>="
%token AND_ASSIGN "&="
%token OR_ASSIGN "|="
%token XOR_ASSIGN "^="
%token AUTO "auto"
%token BREAK "break"
%token CASE "case"
%token CHAR "char"
%token CONST "const"
%token CONTINUE "continue"
%token DEFAULT "default"
%token DO "do"
%token DOUBLE "double"
%token ELSE "else"
%token ENUM "enum"
%token EXTERN "extern"
%token FLOAT "float"
%token FOR "for"
%token GOTO "goto"
%token IF "if"
%token INT "int"
%token LONG "long"
%token REGISTER "register"
%token RETURN "return"
%token SHORT "short"
%token SIGNED "signed"
%token SIZEOF "sizeof"
%token STATIC "static"
%token STRUCT "struct"
%token SWITCH "switch"
%token TYPEDEF "typedef"
%token UNION "union"
%token UNSIGNED "unsigned"
%token VOID "void"
%token VOLATILE "volatile"
%token WHILE "while"

%start translation-unit

%%

identifier
: IDENTIFIER
;

signed.opt
: %empty
| SIGNED
;

int.opt
: %empty
| INT
;

fundamental-specifier
: VOID
| CHAR
| SIGNED CHAR
| UNSIGNED CHAR
| signed.opt SHORT int.opt
| UNSIGNED SHORT int.opt
| signed.opt int.opt
| UNSIGNED int.opt
| signed.opt LONG int.opt
| UNSIGNED LONG int.opt
| FLOAT
| DOUBLE
| LONG DOUBLE
;

storage-class-specifier
: TYPEDEF
| linkage-specifier
| duration-specifier
;

linkage-specifier.opt
: %empty
| linkage-specifier
;

linkage-specifier
: EXTERN
| STATIC
;

duration-specifier.opt
: %empty
| duration-specifier
;

duration-specifier
: AUTO
| REGISTER
;

type-specifier
: fundamental-specifier
| struct-or-union-specifier
| enum-specifier
| typedef-name
;

type-qualifier.opt
: %empty
| type-qualifier
;

type-qualifier
: CONST
| VOLATILE
;

type-qualifier-list.opt
: %empty
| type-qualifier-list
;

type-qualifier-list
: type-qualifier type-qualifier-list.opt
;

declaration-specifiers
: type-specifier type-qualifier-list.opt
| type-qualifier declaration-specifiers
;

pointer
: '*' type-qualifier-list.opt
;

pointer-list.opt
: %empty
| pointer-list
;

pointer-list
: pointer pointer-list.opt
;

declarator
: pointer-list.opt direct-declarator
;

direct-declarator
: identifier
| '(' declarator ')'
| array-declarator
| function-declarator
;

abstract-declarator
: pointer-list
| pointer-list.opt direct-abstract-declarator

translation-unit.opt
: %empty
| translation-unit
;

translation-unit
: external-declaration translation-unit.opt
:

external-declaration
: linkage-specifier.opt function-definition
| linkage-specifier.opt declaration
;

function-definition-declarator
: identifier '(' parameter-type-list ')'
;

function-definition
: declaration-specifiers function-definition-declarator compound-statement

%%

void yyerror(const char* s) {
  fprintf(stderr, "%s\n", s);
}
