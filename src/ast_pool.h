#ifndef KMC_C89_COMPILER_AST_POOL_H
#define KMC_C89_COMPILER_AST_POOL_H

#include "memory_pool.h"

#define ast_palloc(type, count) \
  palloc(type, ast_pool(), (count))

void initialize_ast_pool(size_t size);

void finalize_ast_pool(void);

MemoryPoolRef ast_pool(void);

#endif  /* KMC_C89_COMPILER_AST_POOL_H */
