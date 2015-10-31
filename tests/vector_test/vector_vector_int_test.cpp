extern "C" {
#include "vector_vector_int.h"
}
#include "gtest/gtest.h"

#define VINT VECTORREF(int)
#define VVINT VECTORREF(VINT)
#define VVINTF(function) VECTORFUNC(VINT, function)

class VectorVectorIntTest : public ::testing::Test {
 protected:
  VectorVectorIntTest() : v(VVINTF(ctor)()) {}
  ~VectorVectorIntTest() {
    VVINTF(dtor)(&v);
  }
  VVINT v;
};
