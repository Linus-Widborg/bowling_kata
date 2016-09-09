//
// Created by liwid on 9/9/16.
//

#include "Frame.h"

void Frame::addFirstShot(int score) {
    first = score;
}

void Frame::addSecondShot(int score) {
    secondShot = score;
}

int Frame::score() {
    return first + secondShot;
}

int Frame::getFirstShot() {
    return first;
}
