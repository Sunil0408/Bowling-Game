// Player.cpp
#include "Player.h"

void Player::addFrame(const Frame& frame) 
{
    gameFrames.push_back(frame);
}

int Player::totalScore() const 
{
    int totalScore = 0;

    //traverse through Frames
    for (size_t i = 0; i < gameFrames.size(); ++i) 
    {
        //add first and second throw score in total
        totalScore += gameFrames[i].getFirst() + gameFrames[i].getSecond();

        // Check if Strike and applicable for bonus for Strike
        if (gameFrames[i].isStrike() && (i + 1 < gameFrames.size())) 
        {
            totalScore += gameFrames[i + 1].getFirst(); //first bonus after strike

            //next is also stike
            if (gameFrames[i + 1].isStrike() && (i + 2 < gameFrames.size())) 
            {
                totalScore += gameFrames[i + 2].getFirst(); //second bonus after strike
            }
            else //if not strike
            {
                totalScore += gameFrames[i + 1].getSecond(); //second bonus after srike
            }
        }
        //check for Spare
        else if (gameFrames[i].isSpare() && (i + 1 < gameFrames.size())) 
        {
            totalScore += gameFrames[i + 1].getFirst(); //add Spare bonus if applicable
        }

        // Frame 10 Handling
        if (i == 9 && gameFrames[i].bonusAvailable()) 
        {
            totalScore += gameFrames[i].getBonus(); //add bonus throw score 
        }
    }
    return totalScore;
}

//method to return Frame Vec as it is private
const std::vector<Frame>& Player::getFrames() const 
{
    return gameFrames;
}
