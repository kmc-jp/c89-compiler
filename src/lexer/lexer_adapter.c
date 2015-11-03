#include <stdio.h>
#include <stdlib.h>
#include "lexer/lex.yy.h"
#include "lexer/yacc_mock.h"
#include "lexer/lexer_adapter.h"

void yyin_from_file(const char *filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("fatal error: failed to open %s\n", filename);
    exit(EXIT_FAILURE);
  }
  yyin = fp;
}

void yyin_from_string(char *code, int size) {
  FILE *fp = fmemopen(code, size + 1, "r");
  if (fp == NULL) {
    printf("fatal error: failed to open stream\n");
    exit(EXIT_FAILURE);
  }
}
