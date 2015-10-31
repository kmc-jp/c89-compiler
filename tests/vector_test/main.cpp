#include "gtest/gtest.h"
extern "C" {
#include "use_vector.h"
#include "vector_vector_int.h"
}

class VectorIntEnvironment : public ::testing::Environment {
  virtual void SetUp() {
    INITIALIZE_DEFAULT_METHODS(int);
  }
};

class VectorVectorIntEnvironment : public ::testing::Environment {
  virtual void SetUp() {
    INITIALIZE_DEFAULT_VECTOR_METHODS(int);
  }
};

GTEST_API_ int main(int argc, char **argv) {
  ::testing::AddGlobalTestEnvironment(new VectorIntEnvironment);
  ::testing::AddGlobalTestEnvironment(new VectorVectorIntEnvironment);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
