#include <iostream>
#include "BowlingResult.h"

int BowlingResult::getScoreForRound(int round) {
    int score;
    if (round > rounds.size()) {
        score = 0;
    } else {
        score = rounds[round - 1].score();
    }
    return score;
}

void BowlingResult::addRound(Round round) throw(std::overflow_error) {
    if (rounds.size() >= 10) {
        throw std::overflow_error("more then 10 rounds are not allowed");
    }
    rounds.push_back(round);
}

int BowlingResult::totalScore() {
    int score;
    for(Round round : rounds) {
        score += round.score();
    }
    return score;
}
