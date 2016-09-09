#ifndef TRAINING_BOWLINGRESULT_H
#define TRAINING_BOWLINGRESULT_H

#include <vector>
#include <stdexcept>
#include "Round.h"

class BowlingResult {

public:
    int getScoreForRound(int round);

    void addRound(Round round) throw(std::overflow_error);

    int totalScore();

private:
    std::vector<Round> rounds;
};


#endif //TRAINING_BOWLINGRESULT_H
