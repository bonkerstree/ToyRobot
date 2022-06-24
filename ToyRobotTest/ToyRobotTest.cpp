#include "pch.h"

class ToyRobotTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
      robot.setBounds(5,5);
    }
    
    ToyRobot robot;
};

// test name format: MethodName_StateUnderTest_ExpectedBehaviour
TEST_F(ToyRobotTest, getPosition_PositionNotSet_ReturnInvalidPosition)
{
  EXPECT_EQ(robot.getPosition().x, -1);
  EXPECT_EQ(robot.getPosition().y, -1);
}

TEST_F(ToyRobotTest, setPosition_PositionSetToOrigin_RobotOnOrigin)
{
  bool isValidPosition = robot.setPosition(0,0);

  EXPECT_TRUE(isValidPosition);
  EXPECT_EQ(robot.getPosition().x, 0);
  EXPECT_EQ(robot.getPosition().y, 0);
}

TEST_F(ToyRobotTest, setPosition_PositionSetToInvalidX_PositionNotSet)
{
  bool isValidPosition = robot.setPosition(20,0);

  EXPECT_FALSE(isValidPosition);
  EXPECT_EQ(robot.getPosition().x, -1);
  EXPECT_EQ(robot.getPosition().y, -1);
}

TEST_F(ToyRobotTest, setPosition_PositionSetToInvalidY_PositionNotSet)
{
  bool isValidPosition = robot.setPosition(0,20);

  EXPECT_FALSE(isValidPosition);
  EXPECT_EQ(robot.getPosition().x, -1);
  EXPECT_EQ(robot.getPosition().y, -1);
}

TEST_F(ToyRobotTest, setPosition_OnOriginSetToInvalidPosition_RobotOnOrigin)
{
  robot.setPosition(0,0);
  bool isValidPosition = robot.setPosition(20,20);

  EXPECT_FALSE(isValidPosition);
  EXPECT_EQ(robot.getPosition().x, 0);
  EXPECT_EQ(robot.getPosition().y, 0);
}

TEST_F(ToyRobotTest, getOrientation_OrientationNotSet_ReturnOrientationNone)
{
  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::North);
}

TEST_F(ToyRobotTest, setOrientation_OrientationSetToNorth_RobotFacesNorth)
{
  robot.setOrientation(ToyRobot::Orientation::North);

  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::North);
}

TEST_F(ToyRobotTest, moveForward_OnOriginAndFacesNorth_IncrementMovementNorthByOne)
{
  robot.setPosition(0,0);
  robot.setOrientation(ToyRobot::Orientation::North);
  bool isValidMove = robot.moveForward();

  EXPECT_TRUE(isValidMove);
  EXPECT_EQ(robot.getPosition().x, 0);
  EXPECT_EQ(robot.getPosition().y, 1);
  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::North);
}

TEST_F(ToyRobotTest, moveForward_OnOriginAndFacesEast_IncrementMovementEastByOne)
{
  robot.setPosition(0,0);
  robot.setOrientation(ToyRobot::Orientation::East);
  bool isValidMove = robot.moveForward();

  EXPECT_TRUE(isValidMove);
  EXPECT_EQ(robot.getPosition().x, 1);
  EXPECT_EQ(robot.getPosition().y, 0);
  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::East);
}

TEST_F(ToyRobotTest, moveForward_OnOppositeOriginAndFacesSouth_IncrementMovementSouthByOne)
{
  robot.setPosition(4,4);
  robot.setOrientation(ToyRobot::Orientation::South);
  bool isValidMove = robot.moveForward();

  EXPECT_TRUE(isValidMove);
  EXPECT_EQ(robot.getPosition().x, 4);
  EXPECT_EQ(robot.getPosition().y, 3);
  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::South);
}

TEST_F(ToyRobotTest, moveForward_OnOppositeOriginAndFacesWest_IncrementMovementWestByOne)
{
  robot.setPosition(4,4);
  robot.setOrientation(ToyRobot::Orientation::West);
  bool isValidMove = robot.moveForward();

  EXPECT_TRUE(isValidMove);
  EXPECT_EQ(robot.getPosition().x, 3);
  EXPECT_EQ(robot.getPosition().y, 4);
  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::West);
}

TEST_F(ToyRobotTest, moveForward_OnOriginAndFacesWest_SamePosition)
{
  robot.setPosition(0,0);
  robot.setOrientation(ToyRobot::Orientation::West);
  bool isValidMove = robot.moveForward();

  EXPECT_FALSE(isValidMove);
  EXPECT_EQ(robot.getPosition().x, 0);
  EXPECT_EQ(robot.getPosition().y, 0);
  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::West);
}

TEST_F(ToyRobotTest, moveForward_OnOriginAndFacesSouth_SamePosition)
{
  robot.setPosition(0,0);
  robot.setOrientation(ToyRobot::Orientation::South);
  bool isValidMove = robot.moveForward();

  EXPECT_FALSE(isValidMove);
  EXPECT_EQ(robot.getPosition().x, 0);
  EXPECT_EQ(robot.getPosition().y, 0);
  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::South);
}

TEST_F(ToyRobotTest, moveForward_OnOppositeOriginAndFacesEast_SamePosition)
{
  robot.setPosition(4,4);
  robot.setOrientation(ToyRobot::Orientation::East);
  bool isValidMove = robot.moveForward();

  EXPECT_FALSE(isValidMove);
  EXPECT_EQ(robot.getPosition().x, 4);
  EXPECT_EQ(robot.getPosition().y, 4);
  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::East);
}

TEST_F(ToyRobotTest, moveForward_OnOppositeOriginAndFacesNorth_SamePosition)
{
  robot.setPosition(4,4);
  robot.setOrientation(ToyRobot::Orientation::North);
  bool isValidMove = robot.moveForward();

  EXPECT_FALSE(isValidMove);
  EXPECT_EQ(robot.getPosition().x, 4);
  EXPECT_EQ(robot.getPosition().y, 4);
  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::North);
}

TEST_F(ToyRobotTest, rotateLeft_RobotFacesNorth_RobotFacesWest)
{
  robot.setPosition(4,4);
  robot.setOrientation(ToyRobot::Orientation::North);
  robot.rotateLeft();

  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::West);
}

TEST_F(ToyRobotTest, rotateRight_RobotFacesWest_RobotFacesNorth)
{
  robot.setPosition(4,4);
  robot.setOrientation(ToyRobot::Orientation::West);
  robot.rotateRight();

  EXPECT_EQ(robot.getOrientation(), ToyRobot::Orientation::North);
}