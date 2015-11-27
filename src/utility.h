#ifndef KMC_C89_COMPILER_UTILITY_H
#define KMC_C89_COMPILER_UTILITY_H

#include <stddef.h>

#define UNUSED(x) (void)(x)
#define CONCATENATE(x, y) x ## y
#define CONCATENATE3(x, y, z) x ## y ## z
#define CONCAT(x, y) CONCATENATE(x, y)
#define CONCAT3(x, y, z) CONCATENATE3(x, y, z)
#define TBRACKET(x) CONCAT3(T, x, T)
#define TEMPLATE(type, identifier) CONCAT(identifier, TBRACKET(type))

#ifndef __cplusplus
typedef signed char bool;
#define true ((bool)1)
#define false ((bool)0)
#endif  /* __cplusplus */

void* safe_malloc_impl(size_t size);
#define safe_malloc(type)                       \
  (type*)safe_malloc_impl(sizeof(type))
#define safe_array_malloc(type, size)           \
  (type*)safe_malloc_impl(sizeof(type) * (size))

void safe_free_impl(void* ptr);
#define safe_free(ptr)                          \
  do { safe_free_impl(ptr); ptr = NULL; } while(false)

/* size <= capacity && capacity == pow(2, n) */
size_t enough_capacity(size_t size);

void memory_copy(void* dst, const void* src, size_t size, size_t count);
void memory_move(void* dst, const void* src, size_t size, size_t count);

#endif  /* KMC_C89_COMPILER_UTILITY_H */
