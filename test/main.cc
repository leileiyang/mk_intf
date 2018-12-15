#include "gtest/gtest.h"

#include <string.h>

#include "../src/shcom.hh"

class MkIntfTest: public ::testing::Test {
 protected:
  void SetUp() override {
    initEmc();
    retry_time_ = 10.0;
    retry_interval_ = 1.0;
    strcpy(emc_nmlfile, "linuxcnc.nml");
  }

  void TearDown() override {
    emcShutdown();
  }

 double retry_time_;
 double retry_interval_;

};

TEST_F(MkIntfTest, TryNml) {
  int ret = tryNml(retry_time_, retry_interval_);
  EXPECT_EQ(ret, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
