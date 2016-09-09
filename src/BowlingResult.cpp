#include <iostream>
#include "BowlingResult.h"

int BowlingResult::getScoreForFrame(int number) {
    int score;
    if (number > frames.size()) {
        score = 0;
    } else {
        score = frames[number - 1].score();
    }
    return score;
}

void BowlingResult::addFrame(Frame frame) throw(std::overflow_error) {
    if (frames.size() >= 10) {
        throw std::overflow_error("more then 10 frames are not allowed");
    }
    frames.push_back(frame);
}

int BowlingResult::totalScore() {
    int score;
    bool bonus;
    for(Frame frame : frames) {
        score += frame.score();
        if (bonus) {
            score += frame.getFirstShot();
            bonus = false;
        }
        if (score == 10) {
            bonus = true;
        }
    }
    return score;
}
