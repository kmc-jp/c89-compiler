%code {
#include <stdio.h>
void yyerror(const char *);
}

%code provides {
int yylex(void);
void set_yyin_file(const char *filename);
void set_yyin_string(const char *code);
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
| '(' expression ')'
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
| address-of-expression
| pointer-dereference-expression
| unary-plus-expression
| unary-minus-expression
| bitwise-NOT-expression
| logical-NOT-expression
| sizeof-expression
| sizeof-type-expression
;

prefix-increment-expression
: "++" unary-expression
;

prefix-decrement-expression
: "--" unary-expression
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

sizeof-expression
: "sizeof" unary-expression
;

sizeof-type-expression
: "sizeof" '(' type-name ')'
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
| equal-to-expression
| not-equal-to-expression
;

equal-to-expression
: equality-expression "==" relational-expression
;

not-equal-to-expression
: equality-expression "!=" relational-expression
;

bitwise-AND-expression
: equality-expression
| bitwise-AND-operator-expression
;

bitwise-AND-operator-expression
: bitwise-AND-expression '&' equality-expression
;

bitwise-XOR-expression
: bitwise-AND-expression
| bitwise-XOR-operator-expression
;

bitwise-XOR-operator-expression
: bitwise-XOR-expression '^' bitwise-AND-expression
;

bitwise-OR-expression
: bitwise-XOR-expression
| bitwise-OR-operator-expression
;

bitwise-OR-operator-expression
: bitwise-OR-expression '|' bitwise-XOR-expression
;

logical-AND-expression
: bitwise-OR-expression
| logical-AND-operator-expression
;

logical-AND-operator-expression
: logical-AND-expression "&&" bitwise-OR-expression
;

logical-OR-expression
: logical-AND-expression
| logical-OR-operator-expression
;

logical-OR-operator-expression
: logical-OR-expression "||" logical-AND-expression
;

conditional-expression
: logical-OR-expression
| conditional-operator-expression
;

conditional-operator-expression
: logical-OR-expression '?' expression ':' conditional-expression
;

assignment-expression
: conditional-expression
| basic-assignment-expression
| multiplication-assignment-expression
| division-assignment-expression
| modulo-assignment-expression
| addition-assignment-expression
| subtraction-assignment-expression
| left-shift-assignment-expression
| right-shift-assignment-expression
| bitwise-AND-assignment-expression
| bitwise-XOR-assignment-expression
| bitwise-OR-assignment-expression
;

basic-assignment-expression
: unary-expression '=' assignment-expression
;

multiplication-assignment-expression
: unary-expression "*=" assignment-expression
;

division-assignment-expression
: unary-expression "/=" assignment-expression
;

modulo-assignment-expression
: unary-expression "%=" assignment-expression
;

addition-assignment-expression
: unary-expression "+=" assignment-expression
;

subtraction-assignment-expression
: unary-expression "-=" assignment-expression
;

left-shift-assignment-expression
: unary-expression "<<=" assignment-expression
;

right-shift-assignment-expression
: unary-expression ">>=" assignment-expression
;

bitwise-AND-assignment-expression
: unary-expression "&=" assignment-expression
;

bitwise-XOR-assignment-expression
: unary-expression "^=" assignment-expression
;

bitwise-OR-assignment-expression
: unary-expression "|=" assignment-expression
;

expression.opt
: /* empty */
| expression
;

expression
: assignment-expression
| comma-expression
;

comma-expression
: expression ',' assignment-expression
;

constant-expression.opt
: /* empty */
| constant-expression
;

constant-expression
: conditional-expression
;

declaration
: declaration-specifier-list init-declarator-list.opt ';'
;

declaration-specifier-list.opt
: /* empty */
| declaration-specifier-list
;

declaration-specifier-list
: declaration-specifier declaration-specifier-list.opt
;

declaration-specifier
: storage-class-specifier
| type-specifier
| type-qualifier
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
| declarator-with-initializer
;

declarator-with-initializer
: declarator '=' initializer
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
: struct-or-union-definition
| struct-or-union-declaration
;

struct-or-union-definition
: struct-or-union identifier.opt '{' struct-declaration-list '}'
;

struct-or-union-declaration
: struct-or-union identifier
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
: specifier-qualifier specifier-qualifier-list.opt
;

specifier-qualifier
: type-specifier
| type-qualifier
;

struct-declarator-list
: struct-declarator
| struct-declarator-list ',' struct-declarator
;

struct-declarator
: declarator
| bit-field-declarator
;

bit-field-declarator
: declarator.opt ':' constant-expression
;

enum-specifier
: enum-definition
| enum-declaration
;

enum-definition
: "enum" identifier.opt '{' enumerator-list '}'
;

enum-declaration
: "enum" identifier
;

enumerator-list
: enumerator
| enumerator-list ',' enumerator
;

enumerator
: enumeration-constant
| enumerator-with-initializer
;

enumerator-with-initializer
: enumeration-constant '=' constant-expression
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
| '(' declarator ')'
| array-declarator
| function-declarator
| old-style-function-declarator
;

array-declarator
: direct-declarator '[' constant-expression.opt ']'
;

function-declarator
: direct-declarator '(' parameter-type-list ')'
;

old-style-function-declarator
: direct-declarator '(' identifier-list.opt ')'
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
| variadic-parameter-list
;

variadic-parameter-list
: parameter-list ',' "..."
;

parameter-list
: parameter-declaration
| parameter-list ',' parameter-declaration
;

parameter-declaration
: parameter-concrete-declaration
| parameter-abstract-declaration
;

parameter-concrete-declaration
: declaration-specifier-list declarator
;

parameter-abstract-declaration
: declaration-specifier-list abstract-declarator.opt
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
| pointer-abstract-declarator
;

pointer-abstract-declarator
: pointer.opt direct-abstract-declarator
;

direct-abstract-declarator.opt
: /* empty */
| direct-abstract-declarator
;

direct-abstract-declarator
: '(' abstract-declarator ')'
| array-abstract-declarator
| function-abstract-declarator
;

array-abstract-declarator
: direct-abstract-declarator.opt '[' constant-expression.opt ']'
;

function-abstract-declarator
: direct-abstract-declarator.opt '(' parameter-type-list.opt ')'
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
: identifier-labeled-statement
| case-labeled-statement
| default-labeled-statement
;

identifier-labeled-statement
: identifier ':' statement
;

case-labeled-statement
: "case" constant-expression ':' statement
;

default-labeled-statement
: "default" ':' statement
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
| "return" ';'
| "return" expression ';'
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
: declaration-specifier-list.opt declarator declaration-list.opt compound-statement
;

%%

void yyerror(const char* s) {
  fprintf(stderr, "%s\n", s);
}
