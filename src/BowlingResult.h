#ifndef TRAINING_BOWLINGRESULT_H
#define TRAINING_BOWLINGRESULT_H

#include <vector>
#include <stdexcept>
#include "Frame.h"

class BowlingResult {

public:
    int getScoreForFrame(int number);

    void addFrame(Frame frame) throw(std::overflow_error);

    int totalScore();

private:
    std::vector<Frame> frames;
};


#endif //TRAINING_BOWLINGRESULT_H
