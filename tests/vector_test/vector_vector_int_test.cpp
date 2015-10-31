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

TEST_F(VectorVectorIntTest, ctor) {
  EXPECT_EQ(NULL, VVINTF(data)(v));
  EXPECT_EQ(NULL, VVINTF(begin)(v));
  EXPECT_EQ(NULL, VVINTF(end)(v));
  EXPECT_TRUE(VVINTF(empty)(v));
  EXPECT_EQ(0U, VVINTF(size)(v));
  EXPECT_EQ(0U, VVINTF(capacity)(v));
}
