extern "C" {
#include "use_vector.h"
}
#include "gtest/gtest.h"

#define VINT VECTORREF(int)
#define VVINT VECTORREF(VINT)
#define VVINTF(function) VECTORFUNC(VINT, function)
