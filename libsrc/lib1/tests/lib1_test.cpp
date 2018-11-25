//
// Created by José Edmilson V. dos Santos Jr. on 2018-11-09.
//

#include <gtest/gtest.h>
#include <lib1/lib1.h>

Lib1 lib1;

TEST(lib1_test, ok){
    EXPECT_EQ(lib1.getText(),"TEST_DEF defined");
}

TEST(lib1_test, nok){
    EXPECT_NE(lib1.getText(),"TEST_DEF _NOT_ defined");
}
