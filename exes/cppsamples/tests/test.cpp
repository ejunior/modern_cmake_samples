#include <gtest/gtest.h>
#include "../src/samples.h"

TEST(testaBagaca, NomeIgualAJunior ){
  EXPECT_EQ("Junior", getName());
}

TEST(testaBagaca, NomeIgualNotAJunior ){
  EXPECT_EQ("NotJunior", getName());
}


int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}