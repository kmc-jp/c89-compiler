%code {
#include <stdio.h>
void yyerror(const char *);
}

%code provides {
int yylex(void);
}

%code requires {
#include "ast.h"
#define YYSTYPE AstRef
}

%token IDENTIFIER
%token FLOATING_CONSTANT
%token INTEGER_CONSTANT
%token CHARACTER_CONSTANT
%token STRING_LITERAL

%start translation-unit

%%

identifier.opt
: /* empty */
| identifier
;

identifier
: IDENTIFIER
;

constant
: floating-constant
| integer-constant
| enumeration-constant
| character-constant
;

floating-constant
: FLOATING_CONSTANT
;

integer-constant
: INTEGER_CONSTANT
;

enumeration-constant
: identifier
;

character-constant
: CHARACTER_CONSTANT
;

string-literal
: STRING_LITERAL
;

primary-expression
: identifier
| constant
| string-literal
;

postfix-expression
: primary-expression
| array-subscript-expression
| function-call-expression
| member-access-expression
| member-access-through-pointer-expression
| postfix-increment-expression
| postfix-decrement-expression
;

array-subscript-expression
: postfix-expression '[' expression ']'
;

function-call-expression
: postfix-expression '(' argument-expression-list.opt ')'
;

member-access-expression
: postfix-expression '.' identifier
;

member-access-through-pointer-expression
: postfix-expression "->" identifier
;

postfix-increment-expression
: postfix-expression "++"
;

postfix-decrement-expression
: postfix-expression "--"
;

argument-expression-list.opt
: /* empty */
| argument-expression-list
;

argument-expression-list
: assignment-expression
| argument-expression-list ',' assignment-expression
;

unary-expression
: postfix-expression
| prefix-increment-expression
| prefix-decrement-expression
| unary-operator-expression
| sizeof-expression
| sizeof-type-expression
;

prefix-increment-expression
: "++" unary-expression
;

prefix-decrement-expression
: "--" unary-expression
;

unary-operator-expression
: address-of-expression
| pointer-dereference-expression
| unary-plus-expression
| unary-minus-expression
| bitwise-NOT-expression
| logical-NOT-expression
;

sizeof-expression
: "sizeof" unary-expression
;

sizeof-type-expression
: "sizeof" '(' type-name ')'
;

address-of-expression
: '&' cast-expression
;

pointer-dereference-expression
: '*' cast-expression
;

unary-plus-expression
: '+' cast-expression
;

unary-minus-expression
: '-' cast-expression
;

bitwise-NOT-expression
: '~' cast-expression
;

logical-NOT-expression
: '!' cast-expression
;

cast-expression
: unary-expression
| type-cast-expression
;

type-cast-expression
: '(' type-name ')' cast-expression
;

multiplicative-expression
: cast-expression
| product-expression
| division-expression
| modulo-expression
;

product-expression
: multiplicative-expression '*' cast-expression
;

division-expression
: multiplicative-expression '/' cast-expression
;

modulo-expression
: multiplicative-expression '%' cast-expression
;

additive-expression
: multiplicative-expression
| addition-expression
| subtraction-expression
;

addition-expression
: additive-expression '+' multiplicative-expression
;

subtraction-expression
: additive-expression '-' multiplicative-expression
;

shift-expression
: additive-expression
| left-shift-expression
| right-shift-expression
;

left-shift-expression
: shift-expression "<<" additive-expression
;

right-shift-expression
: shift-expression ">>" additive-expression
;

relational-expression
: shift-expression
| less-than-expression
| greater-than-expression
| less-than-or-equal-to-expression
| greater-than-or-equal-to-expression
;

less-than-expression
: relational-expression '<' shift-expression
;

greater-than-expression
: relational-expression '>' shift-expression
;

less-than-or-equal-to-expression
: relational-expression "<=" shift-expression
;

greater-than-or-equal-to-expression
: relational-expression ">=" shift-expression
;

equality-expression
: relational-expression
| equality-expression "==" relational-expression
| equality-expression "!=" relational-expression
;

AND-expression
: equality-expression
| AND-expression '&' equality-expression
;

exclusive-OR-expression
: AND-expression
| exclusive-OR-expression '^' AND-expression
;

inclusive-OR-expression
: exclusive-OR-expression
| inclusive-OR-expression '|' exclusive-OR-expression
;

logical-AND-expression
: inclusive-OR-expression
| logical-AND-expression "&&" inclusive-OR-expression
;

logical-OR-expression
: logical-AND-expression
| logical-OR-expression "||" logical-AND-expression
;

conditional-expression
: logical-OR-expression
| logical-OR-expression '?' expression ':' conditional-expression
;

assignment-expression
: conditional-expression
| unary-expression assignment-operator assignment-expression
;

assignment-operator
: '='
| "*="
| "/="
| "%="
| "+="
| "-="
| "<<="
| ">>="
| "&="
| "^="
| "|="
;

expression.opt
: /* empty */
| expression
;

expression
: assignment-expression
| expression ',' assignment-expression
;

constant-expression.opt
: /* empty */
| constant-expression
;

constant-expression
: conditional-expression
;

declaration
: declaration-specifiers init-declarator-list.opt ';'
;

declaration-specifiers.opt
: /* empty */
| declaration-specifiers
;

declaration-specifiers
: storage-class-specifier declaration-specifiers.opt
| type-specifier declaration-specifiers.opt
| type-qualifier declaration-specifiers.opt
;

init-declarator-list.opt
: /* empty */
| init-declarator-list
;

init-declarator-list
: init-declarator
| init-declarator-list ',' init-declarator
;

init-declarator
: declarator
| declarator '=' initializer
;

storage-class-specifier
: "typedef"
| "extern"
| "static"
| "auto"
| "register"
;

type-specifier
: "void"
| "char"
| "short"
| "int"
| "long"
| "float"
| "double"
| "signed"
| "unsigned"
| struct-or-union-specifier
| enum-specifier
| typedef-name
;

struct-or-union-specifier
: struct-or-union identifier.opt '{' struct-declaration-list '}'
| struct-or-union identifier
;

struct-or-union
: "struct"
| "union"
;

struct-declaration-list
: struct-declaration
| struct-declaration-list struct-declaration
;

struct-declaration
: specifier-qualifier-list struct-declarator-list ';'
;

specifier-qualifier-list.opt
: /* empty */
| specifier-qualifier-list
;

specifier-qualifier-list
: type-specifier specifier-qualifier-list.opt
| type-qualifier specifier-qualifier-list.opt
;

struct-declarator-list
: struct-declarator
| struct-declarator-list ',' struct-declarator
;

struct-declarator
: declarator
| declarator.opt ':' constant-expression
;

enum-specifier
: "enum" identifier.opt '{' enumerator-list '}'
| "enum" identifier
;

enumerator-list
: enumerator
| enumerator-list ',' enumerator
;

enumerator
: enumeration-constant
| enumeration-constant '=' constant-expression
;

type-qualifier
: "const"
| "volatile"
;

declarator.opt
: /* empty */
| declarator
;

declarator
: pointer.opt direct-declarator
;

direct-declarator
: identifier
| '{' declarator '}'
| direct-declarator '[' constant-expression.opt ']'
| direct-declarator '(' parameter-type-list ')'
| direct-declarator '(' identifier-list.opt ')'
;

pointer.opt
: /* empty */
| pointer
;

pointer
: '*' type-qualifier-list.opt
| '*' type-qualifier-list.opt pointer
;

type-qualifier-list.opt
: /* empty */
| type-qualifier-list
;

type-qualifier-list
: type-qualifier
| type-qualifier-list type-qualifier
;

parameter-type-list.opt
: /* empty */
| parameter-type-list
;

parameter-type-list
: parameter-list
| parameter-list ',' "..."
;

parameter-list
: parameter-declaration
| parameter-list ',' parameter-declaration
;

parameter-declaration
: declaration-specifiers declarator
| declaration-specifiers abstract-declarator.opt
;

identifier-list.opt
: /* empty */
| identifier-list
;

identifier-list
: identifier
| identifier-list ',' identifier
;

type-name
: specifier-qualifier-list abstract-declarator.opt
;

abstract-declarator.opt
: /* empty */
| abstract-declarator
;

abstract-declarator
: pointer
| pointer.opt direct-abstract-declarator
;

direct-abstract-declarator.opt
: /* empty */
| direct-abstract-declarator
;

direct-abstract-declarator
: '(' abstract-declarator ')'
| direct-abstract-declarator.opt '[' constant-expression.opt ']'
| direct-abstract-declarator.opt '(' parameter-type-list.opt ')'
;

typedef-name
: identifier
;

initializer
: assignment-expression
| '{' initializer '}'
| '{' initializer-list ',' '}'
;

initializer-list
: initializer
| initializer-list ',' initializer
;

statement
: labeled-statement
| compound-statement
| expression-statement
| selection-statement
| iteration-statement
| jump-statement
;

labeled-statement
: identifier ':' statement
| "case" constant-expression ':' statement
| "default" ':' statement
;

compound-statement
: '{' declaration-list.opt statement-list.opt '}'
;

declaration-list.opt
: /* empty */
| declaration-list
;

declaration-list
: declaration
| declaration-list declaration
;

statement-list.opt
: /* empty */
| statement-list
;

statement-list
: statement
| statement-list statement
;

expression-statement
: expression.opt ';'
;

selection-statement
: "if" '(' expression ')' statement
| "if" '(' expression ')' statement "else" statement
| "switch" '(' expression ')' statement
;

iteration-statement
: "while" '(' expression ')' statement
| "do" statement "while" '(' expression ')' ';'
| "for" '(' expression.opt ';' expression.opt ';' expression.opt ')' statement
;

jump-statement
: "goto" identifier ';'
| "continue" ';'
| "break" ';'
| "return" expression.opt ';'
;

translation-unit
: external-declaration
| translation-unit external-declaration
;

external-declaration
: function-definition
| declaration
;

function-definition
: declaration-specifiers.opt declarator declaration-list.opt compound-statement
;

%%

void yyerror(const char* s) {
  fprintf(stderr, "%s\n", s);
}
