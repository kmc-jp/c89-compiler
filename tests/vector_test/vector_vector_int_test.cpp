extern "C" {
#include "vector_vector_int.h"
}
#include "gtest/gtest.h"

#define VINT VECTORREF(int)
#define VVINT VECTORREF(VINT)
#define VVINTF(function) VECTORFUNC(VINT, function)
