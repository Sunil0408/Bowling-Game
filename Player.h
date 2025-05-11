// Player.h
#pragma once

#include <vector>
#include "Frame.h"

class Player {
private:
    std::vector<Frame> gameFrames;

public:
    void addFrame(const Frame& frame);
    int totalScore() const;
    const std::vector<Frame>& getFrames() const;
};
