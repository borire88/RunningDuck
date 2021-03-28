#include "../Core/Src/Motor.cpp"
#include "../Core/Src/MockDigitalOut.cpp"
#include "../Core/Src/Encoder.cpp"
#include <gtest/gtest.h>
#include <math.h>

TEST(MotorRampUpTest, PositiveSpeed) {
   MockDigitalOut a(1),b(1),c(1);
   Motor motor(&a,&b,&c);
   int speed = motor.getSpeed();
   ASSERT_EQ(0, speed);
   for(int i = 0; i <= 100; i++) {
      motor.setSpeed(i);
      speed = motor.getSpeed();
      ASSERT_EQ(i, speed);
   }
}

TEST(MotorRampUpTest, NegativeSpeed) {
   MockDigitalOut a(1),b(1),c(1);
   Motor motor(&a,&b,&c);
   int speed = motor.getSpeed();
   ASSERT_EQ(0, speed);
   for(int i = -100; i <= 0; i++) {
      motor.setSpeed(i);
      speed = motor.getSpeed();
      ASSERT_EQ(std::abs(i), speed);
   }
}

TEST(MotorBreakingTest, Breaking) {
   MockDigitalOut a(1),b(1),c(1);
   Motor motor(&a,&b,&c);
   int speed = motor.getSpeed();
   ASSERT_EQ(0, speed);
   for(int i = -100; i <= 100; i++) {
      motor.setSpeed(i);
      speed = motor.getSpeed();
      ASSERT_EQ(std::abs(i), speed);
      motor.stop();
      speed = motor.getSpeed();
      ASSERT_EQ(0, speed);
   }
}

TEST(MotorSpeedOutOfRange, Negative) {
   MockDigitalOut a(1),b(1),c(1);
   Motor motor(&a,&b,&c);
   ASSERT_EQ(0, motor.getSpeed());
   motor.setSpeed(-101);
   ASSERT_EQ(100, motor.getSpeed());
}

TEST(MotorSpeedOutOfRange, Positive) {
   MockDigitalOut a(1),b(1),c(1);
   Motor motor(&a,&b,&c);
   ASSERT_EQ(0, motor.getSpeed());
   motor.setSpeed(101);
   ASSERT_EQ(100, motor.getSpeed());
}

TEST(EncoderTest, RotateRight) {
   Encoder encoderToTest(3, false, false, false);
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.fallingEdgeB();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.fallingEdgeA();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.fallingEdgeB();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.fallingEdgeA();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(0, encoderToTest.getPosition());
}

TEST(EncoderTest, RotateLeft) {
   Encoder encoderToTest(3, false, false, false);
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   encoderToTest.risingEdgeB();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.fallingEdgeA();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.fallingEdgeB();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.fallingEdgeA();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.fallingEdgeB();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.fallingEdgeA();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.fallingEdgeB();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(2, encoderToTest.getPosition());
}

TEST(EncoderTest, RotateRightSaturate) {
   Encoder encoderToTest(3, true, false, false);
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.fallingEdgeB();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.fallingEdgeA();
   ASSERT_EQ(1, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.fallingEdgeB();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.fallingEdgeA();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(2, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(2, encoderToTest.getPosition());
}

TEST(EncoderTest, RotateLeftSaturate) {
   Encoder encoderToTest(3, true, false, false);
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   encoderToTest.risingEdgeB();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.fallingEdgeA();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.fallingEdgeB();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.fallingEdgeA();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.fallingEdgeB();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeA();
   ASSERT_EQ(0, encoderToTest.getPosition());
   encoderToTest.risingEdgeB();
   ASSERT_EQ(0, encoderToTest.getPosition());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
