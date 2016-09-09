//
// Created by liwid on 9/9/16.
//

#include "Round.h"

void Round::addFirst(int score) {
    first = score;
}

void Round::addSecond(int score) {
    second = score;
}

int Round::score() {
    return first + second;
}
