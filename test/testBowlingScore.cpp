#include "gtest/gtest.h"
#include "../src/BowlingResult.h"

TEST(test_bowling_score, calculate_the_score_of_one_round) {
    BowlingResult bowlingResult;
    Round round1;
    round1.addFirst(6);
    round1.addSecond(1);
    bowlingResult.addRound(round1);
    int score = bowlingResult.getScoreForRound(1);
    EXPECT_EQ(7, score);
    Round round2;
    round2.addFirst(0);
    round2.addSecond(1);
    bowlingResult.addRound(round2);
    score = bowlingResult.getScoreForRound(2);
    EXPECT_EQ(1, score);
}

TEST(test_bowling_score, un_added_score_for_round_should_be_zero) {
    BowlingResult bowlingResult;
    int score = bowlingResult.getScoreForRound(1);
    EXPECT_EQ(0, score);
}

TEST(test_bowling_score, not_allowed_to_add_more_then_ten_rounds) {
    BowlingResult bowlingResult;
    Round round;
    for (int roundCount = 1; roundCount <= 10; roundCount++) {
        bowlingResult.addRound(round);
    }
    EXPECT_THROW(bowlingResult.addRound(round), std::overflow_error);
}

TEST(test_bowling_score, calculate_the_score_from_several_rounds) {
    BowlingResult bowlingResult;
    Round round1;
    round1.addFirst(3);
    round1.addSecond(3);
    bowlingResult.addRound(round1);
    Round round2;
    round2.addFirst(3);
    round2.addSecond(4);
    bowlingResult.addRound(round2);
    int score = bowlingResult.totalScore();
    EXPECT_EQ(13, score);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}