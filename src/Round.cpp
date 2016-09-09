//
// Created by liwid on 9/9/16.
//

#include "Round.h"

void Round::addFirstShot(int score) {
    first = score;
}

void Round::addSecondShot(int score) {
    secondShot = score;
}

int Round::score() {
    return first + secondShot;
}

int Round::getFirstShot() {
    return first;
}
