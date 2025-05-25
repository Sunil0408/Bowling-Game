// BowlingGame.h
#pragma once

#include <iostream>
#include "Player.h"
#include "Frame.h"

struct PlayerInfo {
    std::string name;
    Player player;
};

class BowlingGame {
private:
    std::vector<PlayerInfo> m_BowlingPlayers;

public:
    void run();
    void showScore() const;
};
