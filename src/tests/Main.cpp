// Copyright Zheng Xian Qiu

#include "gtest/gtest.h"
#include "Seeker.h"

using ::testing::InitGoogleTest;

TEST(BootstrapTest, True) {
  EXPECT_EQ(1, TRUE);
}

int main(int argc, char** argv) {
  InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
