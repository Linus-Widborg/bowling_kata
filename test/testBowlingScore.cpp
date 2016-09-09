#include "gtest/gtest.h"
#include "../src/BowlingResult.h"

TEST(test_bowling_score, calculate_the_score_of_one_frame) {
    BowlingResult bowlingResult;
    Frame frame1;
    frame1.addFirstShot(6);
    frame1.addSecondShot(1);
    bowlingResult.addFrame(frame1);
    int score = bowlingResult.getScoreForFrame(1);
    EXPECT_EQ(7, score);
    Frame frame2;
    frame2.addFirstShot(0);
    frame2.addSecondShot(1);
    bowlingResult.addFrame(frame2);
    score = bowlingResult.getScoreForFrame(2);
    EXPECT_EQ(1, score);
}

TEST(test_bowling_score, un_added_score_for_frame_should_be_zero) {
    BowlingResult bowlingResult;
    int score = bowlingResult.getScoreForFrame(1);
    EXPECT_EQ(0, score);
}

TEST(test_bowling_score, not_allowed_to_add_more_then_ten_frames) {
    BowlingResult bowlingResult;
    Frame frame;
    for (int frameCount = 1; frameCount <= 10; frameCount++) {
        bowlingResult.addFrame(frame);
    }
    EXPECT_THROW(bowlingResult.addFrame(frame), std::overflow_error);
}

TEST(test_bowling_score, calculate_the_score_from_several_frames) {
    BowlingResult bowlingResult;
    Frame frame1;
    frame1.addFirstShot(3);
    frame1.addSecondShot(3);
    bowlingResult.addFrame(frame1);
    Frame frame2;
    frame2.addFirstShot(3);
    frame2.addSecondShot(4);
    bowlingResult.addFrame(frame2);
    int score = bowlingResult.totalScore();
    EXPECT_EQ(6 + 7, score);
}

TEST(test_bowling_score, calculate_the_total_score_with_one_spare) {
    BowlingResult bowlingResult;
    Frame frame1;
    frame1.addFirstShot(3);
    frame1.addSecondShot(7);
    bowlingResult.addFrame(frame1);
    Frame frame2;
    frame2.addFirstShot(3);
    frame2.addSecondShot(4);
    bowlingResult.addFrame(frame2);
    int score = bowlingResult.totalScore();
    EXPECT_EQ(10 + 3 + 7, score);
}

TEST(test_bowling_score, calculate_the_total_score_with_two_spare_in_a_row) {
    BowlingResult bowlingResult;
    Frame frame1;
    frame1.addFirstShot(3);
    frame1.addSecondShot(7);
    bowlingResult.addFrame(frame1);
    Frame frame2;
    frame2.addFirstShot(3);
    frame2.addSecondShot(7);
    bowlingResult.addFrame(frame2);
    Frame frame3;
    frame3.addFirstShot(3);
    frame3.addSecondShot(7);
    bowlingResult.addFrame(frame3);
    int score = bowlingResult.totalScore();
    EXPECT_EQ((10 + 3) + (10 + 3) + 7, score);
}

TEST(test_bowling_score, calculate_the_total_score_with_one_strike) {
    BowlingResult bowlingResult;
    Frame frame1;
    frame1.addFirstShot(10);
    frame1.addSecondShot(0);
    bowlingResult.addFrame(frame1);
    Frame frame2;
    frame2.addFirstShot(3);
    frame2.addSecondShot(6);
    bowlingResult.addFrame(frame2);
    int score = bowlingResult.totalScore();
    EXPECT_EQ((10 + 3 + 6) + 9, score);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}