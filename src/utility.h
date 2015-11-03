#ifndef KMC_C89_COMPILER_UTILITY_H
#define KMC_C89_COMPILER_UTILITY_H

#include <stddef.h>

#define UNUSED(x) (void)(x)

#ifndef __cplusplus
typedef signed char bool;
extern const bool true;
extern const bool false;
#endif  /* __cplusplus */

void* safe_malloc(size_t size);
void safe_free_impl(void** ptr);
#define safe_free(ptr)                          \
  do { safe_free_impl(&ptr); } while(false)

size_t min_size_t(size_t a, size_t b);
size_t max_size_t(size_t a, size_t b);

#endif  /* KMC_C89_COMPILER_UTILITY_H */
