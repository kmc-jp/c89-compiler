#include "sexpr_pool.h"
#include <assert.h>
#include "memory_pool.h"

static const size_t SEXPR_POOL_CHUNK_SIZE = 1024;
static MemoryPoolRef g_sexpr_pool = NULL;

void sexpr_initialize_pool(void) {
  assert(!g_sexpr_pool);
  g_sexpr_pool = memory_pool_ctor(SEXPR_POOL_CHUNK_SIZE);
}

void sexpr_finalize_pool(void) {
  memory_pool_dtor(&g_sexpr_pool);
}
