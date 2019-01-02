#include <unistd.h>

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

//extern int sendManual();
//extern int sendAuto();
//extern int sendMdi();

TEST_F(MkIntfTest, SendInterface) {
  int ret = tryNml(retry_time_, retry_interval_);
  EXPECT_EQ(ret, 0);
  ASSERT_NE(emcStatus, nullptr);

  ret  = sendAuto();
  EXPECT_EQ(ret, 0);
  ret = updateStatus();
  EXPECT_EQ(ret, 0);
  //EXPECT_EQ(emcStatus->task.state, EMC_TASK_STATE_ON);
  EXPECT_EQ(emcStatus->task.mode, EMC_TASK_MODE_AUTO);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
