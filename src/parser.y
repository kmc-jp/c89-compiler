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
%token INTEGER_CONSTANT
%token FLOATING_CONSTANT
%token CHARACTER_CONSTANT
%token STRING_LITERAL

%%

primary-expression
: identifier
| constant
| string-literal
;

postfix-expression
: primary-expression
| postfix-expression '[' expression ']'
| postfix-expression '(' argument-expression-list.opt ')'
| postfix-expression '.' identifier
| postfix-expression '->' identifier
| postfix-expression '++'
| postfix-expression '--'
;

argument-expression-list
: assignment-expression
| argument-expression-list ',' assignment-expression
;

unary-expression
: postfix-expression
| '++' unary-expression
| '--' unary-expression
| unary-operator cast-expression
| 'sizeof' unary-expression
| 'sizeof' '(' type-name ')'
;

unary-operator
: '&'
| '*'
| '+'
| '~'
| '!'
;

cast-expression
: unary-expression
| '(' type-name ')' cast-expression
;

multiplicative-expression
: cast-expression
| multiplicative-expression '*' cast-expression
| multiplicative-expression '/' cast-expression
| multiplicative-expression '%' cast-expression
;

additive-expression
: multiplicative-expression
| additive-expression '+' multiplicative-expression
| additive-expression '-' multiplicative-expression
;

shift-expression
: additive-expression
| shift-expression '<<' additive-expression
| shift-expression '>>' additive-expression
;

relational-expression
: shift-expression
| relational-expression '<' shift-expression
| relational-expression '>' shift-expression
| relational-expression '<=' shift-expression
| relational-expression '>=' shift-expression
;

equality-expression
: relational-expression
| equality-expression '==' relational-expression
| equality-expression '!=' relational-expression
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
| logical-AND-expression '&&' inclusive-OR-expression
;

logical-OR-expression
: logical-AND-expression
| logical-OR-expression '||' logical-AND-expression
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
| '*='
| '/='
| '%='
| '+='
| '-='
| '<<='
| '>>='
| '&='
| '^='
| '|='
;

expression
: assignment-expression
| expression ',' assignment-expression
;

constant-expression
: conditional-expression
;

declaration
: declaration-specifiers init-declarator-list.opt ';'
;

declaration-specifiers
: storage-class-specifier declaration-specifiers.opt
| type-specifier declaration-specifiers.opt
| type-qualifier declaration-specifiers.opt
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
: 'typedef'
| 'extern'
| 'static'
| 'auto'
| 'register'
;

type-specifier
struct-or-union-specifier
: struct-or-union identifier.opt '{' struct-declaration-list '}'
| struct-or-union identifier
;

struct-or-union
: 'struct'
| 'union'
;

struct-declaration-list
: struct-declaration
| struct-declaration-list struct-declaration
;

struct-declaration
: specifier-qualifier-list struct-declarator-list ';'
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
: 'enum' identifier.opt '{' enumerator-list '}'
| 'enum' identifier
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
: 'const'
| 'volatile'
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

pointer
: '*' type-qualifier-list.opt
| '*' type-qualifier-list.opt pointer
;

type-qualifier-list
: type-qualifier
| type-qualifier-list type-qualifier
;

parameter-type-list
: parameter-list
| parameter-list ',' '...'
;

parameter-list
: parameter-declaration
| parameter-list ',' parameter-declaration
;

parameter-declaration
: declaration-specifiers declarator
| declaration-specifiers abstract-declarator.opt
;

identifier-list
: identifier
| identifier-list ',' identifier
;

type-name
: specifier-qualifier-list abstract-declarator.opt
;

abstract-declarator
: pointer
| pointer.opt direct-subabstract-declarator
;

direct-abstract-declarator
: '(' abstract-declarator ')'
| direct-abstract-declarator.opt '[' constant-expression ']'
| direct-abstract-declarator.opt '[' parameter-type-list ']'
;

typedef-name
: identifier
;

initializer
: assignment-expression
| '{' initilizer '}'
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
| 'case' constant-expression ':' statement
| 'default' ':' statement
;

compound-statement
: '{' declaration-list.opt statement-list.opt '}'
;

declaration-list
: declaration
| declaration-list declaration
;

statement-list
: statement
| statement-list statement
;

expression-statement
: expression.opt ';'
;

selection-statement
: 'if' '(' expression ')' statement
| 'if' '(' expression ')' statement 'else' statement
| 'switch' '(' expression ')' statement
;

iteration-statement
: 'while' '(' expression ')' statement
| 'do' statement 'while' '(' expression ')' ';'
| 'for' '(' expression.opt ';' expression.opt ';' expression.opt ')' statement
;

jump-statement
: 'goto' identifier ';'
| 'continue' ';'
| 'break' ';'
| 'return' expression.opt ';'
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
