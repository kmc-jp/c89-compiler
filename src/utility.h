#ifndef KMC_C89_COMPILER_UTILITY_H
#define KMC_C89_COMPILER_UTILITY_H

#include <stddef.h>

#define UNUSED(x) (void)(x)
#define CONCATENATE(x, y) x ## y
#define CONCAT(x, y) CONCATENATE(x, y)

#ifndef __cplusplus
typedef signed char bool;
#define true ((bool)1)
#define false ((bool)0)
#endif  /* __cplusplus */

#ifdef __cplusplus
#define BEGIN_EXTERN_C extern "C" {
#define END_EXTERN_C }
#else
#define BEGIN_EXTERN_C
#define END_EXTERN_C
#endif

void* safe_malloc_impl(size_t size);
#define safe_malloc(type)                       \
  (type*)safe_malloc_impl(sizeof(type))
#define safe_array_malloc(type, size)           \
  (type*)safe_malloc_impl(sizeof(type) * (size))

void safe_free_impl(void* ptr);
#define safe_free(ptr)                          \
  do { safe_free_impl(ptr); ptr = NULL; } while(false)

BEGIN_EXTERN_C

/* size <= capacity && capacity == pow(2, n) */
size_t enough_capacity(size_t size);

void memory_copy(void* dst, const void* src, size_t size, size_t count);
void memory_move(void* dst, const void* src, size_t size, size_t count);

END_EXTERN_C

#endif  /* KMC_C89_COMPILER_UTILITY_H */
