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

        do {
            cout << "  First throw: ";
            cin >> first;

            if (cin.fail() || first < 0 || first > 10) 
            {
                cout << "  Invalid input. Enter a number between 0 and 10.\n";
                cin.clear(); //reset error flag e.g failbit
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //empty buffer to read new input
            }
            else 
            {
                break; // break the loop in case of valid input
            }
        } while (true); //break is there in loop 



        //Second throw - eligible only if not strike or last frame
        if (first != 10 || frame == 10) 
        {
            do {
                cout << "  Second throw: ";
                cin >> second;

                if (cin.fail() || second < 0 || second > 10) 
                {
                    cout << "  Invalid input. Pins must be between 0 and 10. Please try again.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //empty buffer to read new input
                }
                else if (frame != 10 && (first + second) > 10) 
                {
                    cout << "  Invalid input. Total pins in a frame must not exceed 10. Please try again.\n";
                }
                else 
                {
                    break;  // break the loop in case of valid input
                }
            } while (true);//break is there in loop 


        }

        //set first and second throw score
        current.setThrows(first, second);

        //bonus throw - eligible only for 10th frame and if Strike or Spare in first two throws
        if (frame == 10 && (current.isStrike() || current.isSpare())) 
        {
            do {
                cout << "  Bonus throw: ";
                cin >> bonus;

                if (cin.fail() || bonus < 0 || bonus > 10) 
                {
                    cout << "  Invalid input. Pins must be between 0 and 10. Please try again.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //empty buffer to read new input
                }
                else 
                {
                    break;  // break the loop in case of valid input
                }
            } while (true);//break is there in loop 

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
