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

%precedence ONLY_IF
%precedence ELSE

%start translation-unit

%%

identifier
: IDENTIFIER
;

expression.opt
: %empty
| expression
;

expression
: INTEGER_CONSTANT
;

constant-expression
: INTEGER_CONSTANT
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
/* | CHAR */
/* | SIGNED CHAR */
/* | UNSIGNED CHAR */
/* | signed.opt SHORT int.opt */
/* | UNSIGNED SHORT int.opt */
| signed.opt int.opt
/* | UNSIGNED int.opt */
/* | signed.opt LONG int.opt */
/* | UNSIGNED LONG int.opt */
/* | FLOAT */
/* | DOUBLE */
/* | LONG DOUBLE */
;

storage-class-specifier.opt
: %empty
| storage-class-specifier
;

storage-class-specifier
: AUTO
| REGISTER
| STATIC
;

linkage-specifier.opt
: %empty
| linkage-specifier
;

linkage-specifier
: EXTERN
| STATIC
;

type-specifier
: fundamental-specifier
/* | struct-or-union-specifier */
/* | enum-specifier */
/* | typedef-name */
;

/* type-qualifier.opt */
/* : %empty */
/* | type-qualifier */
/* ; */

/* type-qualifier */
/* : CONST */
/* | VOLATILE */
/* ; */

/* type-qualifier-list.opt */
/* : %empty */
/* | type-qualifier-list */
/* ; */

/* type-qualifier-list */
/* : type-qualifier type-qualifier-list.opt */
/* ; */

declaration-specifiers
: type-specifier
/* : type-specifier type-qualifier-list.opt */
/* | type-qualifier declaration-specifiers */
;

declaration
: declaration-specifiers declarator-list
;

declarator-list.opt
: %empty
| ',' declarator-list
;

declarator-list
: declarator declarator-list.opt
;

init-declaration
: declaration-specifiers init-declarator-list
;

init-declarator
: declarator
/* | declarator '=' initializer */
;

init-declarator-list.opt
: %empty
| ',' init-declarator-list
;

init-declarator-list
: init-declarator init-declarator-list.opt
;

/* pointer */
/* : '*' type-qualifier-list.opt */
/* ; */

/* pointer-list.opt */
/* : %empty */
/* | pointer-list */
/* ; */

/* pointer-list */
/* : pointer pointer-list.opt */
/* ; */

declarator
: direct-declarator
/* : pointer-list.opt direct-declarator */
;

direct-declarator
: identifier
/* | '(' declarator ')' */
/* | array-declarator */
/* | function-declarator */
;

/* abstract-declarator.opt */
/* : %empty */
/* | abstract-declarator */
/* ; */

/* abstract-declarator */
/* : pointer-list */
/* | pointer-list.opt direct-abstract-declarator */
/* ; */

/* direct-abstract-declarator */
/* : '(' abstract-declarator ')' */
/* | array-abstract-declarator */
/* | function-abstract-declarator */
/* ; */

parameter-list-tail
: %empty
| ',' parameter-list
;

parameter-list
: parameter-declaration parameter-list-tail
;

parameter-declaration
: declaration-specifiers declarator
/* | declaration-specifiers abstract-declarator.opt */
;

statement
: labeled-statement
| compound-statement
| expression-statement
| selection-statement
| iteration-statement
| jump-statement
;

statement-list.opt
: %empty
| statement-list
;

statement-list
: statement statement-list.opt
;

labeled-statement
: identifier ':' statement
| CASE constant-expression ':' statement
| DEFAULT ':' statement
;

compound-statement
: '{' declaration-statement-list.opt statement-list.opt '}'
;

declaration-statement
: storage-class-specifier.opt init-declaration
| TYPEDEF declaration
;

declaration-statement-list.opt
: %empty
| declaration-statement-list
;

declaration-statement-list
: declaration-statement declaration-statement-list.opt
;

expression-statement
: expression.opt ';'
;

selection-statement
: IF '(' expression ')' statement %prec ONLY_IF
| IF '(' expression ')' statement ELSE statement
| SWITCH '(' expression ')' statement
;

iteration-statement
: WHILE '(' expression ')' statement
| DO statement WHILE '(' expression ')' ';'
| FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement
;

jump-statement
: GOTO identifier ';'
| CONTINUE ';'
| BREAK ';'
| RETURN expression.opt ';'
;

translation-unit.opt
: %empty
| translation-unit
;

translation-unit
: external-declaration translation-unit.opt
;

external-declaration
: linkage-specifier.opt function-definition
| linkage-specifier.opt init-declaration
| TYPEDEF declaration
;

function-definition-declarator
: identifier '(' parameter-list ')'
;

function-definition
: declaration-specifiers function-definition-declarator compound-statement

%%

void yyerror(const char* s) {
  fprintf(stderr, "%s\n", s);
}
