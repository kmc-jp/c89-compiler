#include "use_vector.h"

/* VECTORREF(int) */
DEFINE_VECTOR(int)
DEFINE_DEFAULT_METHODS(int)

/* VECTORREF(VECTORREF(int)) */
DEFINE_VECTOR(VECTORREF(int))
DEFINE_DEFAULT_VECTOR_METHODS(int)
