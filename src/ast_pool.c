#include "ast_pool.h"

static MemoryPoolRef g_ast_pool = NULL;

void initialize_ast_pool(size_t size) {
  if (!g_ast_pool) {
    g_ast_pool = memory_pool_ctor(size);
  }
}

void finalize_ast_pool(void) {
  memory_pool_dtor(&g_ast_pool);
}

MemoryPoolRef ast_pool(void) {
  return g_ast_pool;
}
