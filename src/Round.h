//
// Created by liwid on 9/9/16.
//

#ifndef TRAINING_ROUND_H
#define TRAINING_ROUND_H


class Round {

public:
    void addFirst(int score);

    void addSecond(int score);

    int score();

private:
    int second;
    int first;
};


#endif //TRAINING_ROUND_H
