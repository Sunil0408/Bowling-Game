// BowlingGame.h
#pragma once

#include <iostream>
#include "Player.h"
#include "Frame.h"

class BowlingGame {
private:
    Player player;

public:
    void run();
    void showScore() const;
};
