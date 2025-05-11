// BowlingGame.cpp
#include "BowlingGame.h"
using namespace std;

void BowlingGame::run() 
{
    cout << "Welcome to Bowling Bowl Game!\n\n";
    
    for (int frame = 1; frame <= 10; ++frame) 
    {
        Frame current;
        int first = 0, second = 0, bonus = 0;

        cout << "Frame " << frame << ":\n";
        cout << "  First throw: ";
        cin >> first;

        if (first < 0 || first > 10) 
        {
            throw invalid_argument("Invalid pins for first throw. Pins must be between 0 and 10."); //error can also be replaced with allowing user to correct input
        }

        //Second throw - eligible only if not strike or last frame
        if (first != 10 || frame == 10) 
        {
            cout << "  Second throw: ";
            cin >> second;

            if (second < 0 || second > 10) 
            {
                throw invalid_argument("Invalid pins for second throw. Pins must be between 0 and 10.");
            }
        }

        //set first and second throw score
        current.setThrows(first, second);

        //bonus throw - eligible only for 10th frame and if Strike or Spare in first two throws
        if (frame == 10 && (current.isStrike() || current.isSpare())) 
        {
            cout << "  Bonus throw: ";
            cin >> bonus;
            if (bonus < 0 || bonus > 10)
            {
                throw invalid_argument("Invalid pins for bonus throw. Pins must be between 0 and 10.");
            }
            //set bonus
            current.setBonus(bonus);
        }
        //set frame
        player.addFrame(current);
    }
}

void BowlingGame::showScore() const 
{
    cout << "\nYour final score is : " << player.totalScore() << endl;
}
