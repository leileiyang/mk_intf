#include <unistd.h>

#include "gtest/gtest.h"

#include <string.h>

#include "../src/shcom.hh"

static int g_serial_number = 0;

class MkIntfTest: public ::testing::Test {
 protected:
  void SetUp() override {
    initEmc();
    emcCommandSerialNumber = g_serial_number++;
    retry_time_ = 10.0;
    retry_interval_ = 1.0;
    strcpy(emc_nmlfile, "linuxcnc.nml");
    tryNml(retry_time_, retry_interval_);
  }

  void TearDown() override {
    emcShutdown();
  }

  double retry_time_;
  double retry_interval_;
};

TEST_F(MkIntfTest, TryNml) {
  emcShutdown();
  int ret = tryNml(retry_time_, retry_interval_);
  EXPECT_EQ(ret, 0);
}

TEST_F(MkIntfTest, SendAuto) {
  ASSERT_NE(emcStatus, nullptr);
  ASSERT_NE(emcStatus->status, RCS_ERROR);
  int ret = sendAuto();
  EXPECT_EQ(ret, 0);
  ret = updateStatus();
  EXPECT_EQ(ret, 0);
  EXPECT_EQ(emcStatus->task.mode, EMC_TASK_MODE_AUTO);
}

TEST_F(MkIntfTest, SendMdi) {
  ASSERT_NE(emcStatus, nullptr);
  ASSERT_NE(emcStatus->status, RCS_ERROR);
  int ret = sendMdi();
  EXPECT_EQ(ret, 0);
  ret = updateStatus();
  EXPECT_EQ(ret, 0);
  EXPECT_EQ(emcStatus->task.mode, EMC_TASK_MODE_MDI);
}

TEST_F(MkIntfTest, SendManual) {
  ASSERT_NE(emcStatus, nullptr);
  ASSERT_NE(emcStatus->status, RCS_ERROR);
  int ret = sendManual();
  EXPECT_EQ(ret, 0);
  ret = updateStatus();
  EXPECT_EQ(ret, 0);
  EXPECT_EQ(emcStatus->task.mode, EMC_TASK_MODE_MANUAL);
}
/*
TEST_F(MkIntfTest, SendHome) {
  ASSERT_NE(emcStatus, nullptr);
  ASSERT_NE(emcStatus->status, RCS_ERROR);
  int ret = sendHome(-1);
  EXPECT_EQ(ret, 0);
  ret = updateStatus();
  EXPECT_EQ(ret, 0);
  for (int i = 0; i < EMC_AXIS_MAX; i++) {
    EXPECT_EQ(emcStatus->motion.axis[i].homed, 1);
  }
}

TEST_F(MkIntfTest, SendUnHome) {
  ASSERT_NE(emcStatus, nullptr);
  ASSERT_NE(emcStatus->status, RCS_ERROR);
  int ret = sendUnHome(-1);
  EXPECT_EQ(ret, 0);
  ret = updateStatus();
  EXPECT_EQ(ret, 0);
  for (int i = 0; i < EMC_AXIS_MAX; i++) {
    EXPECT_EQ(emcStatus->motion.axis[i].homed, 0);
  }
}*/


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
