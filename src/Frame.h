#ifndef TRAINING_ROUND_H
#define TRAINING_ROUND_H

class Frame {

public:
    void addFirstShot(int score);

    void addSecondShot(int score);

    int score();

    int getFirstShot();

private:
    int secondShot;
    int first;
};


#endif //TRAINING_ROUND_H
