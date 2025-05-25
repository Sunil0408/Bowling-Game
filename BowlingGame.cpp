// BowlingGame.cpp
#include "BowlingGame.h"
#include <string>
#include <limits> // for numeric_limits
#include <iostream>

using namespace std;

void BowlingGame::run()
{
    cout << "Welcome to Bowling Bowl Game!\n\n";

    int numPlayers = 0;
    cout << "Enter number of players: ";
    cin >> numPlayers;

    while (numPlayers <= 0)
    {
        cout << "Invalid number. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> numPlayers;
    }

    // Clear newline before getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Get player names
    for (int i = 0; i < numPlayers; ++i)
    {
        string name;
        cout << "Enter name for Player " << (i + 1) << ": ";
        getline(cin, name);
        m_BowlingPlayers.push_back({ name, Player() });
    }

    // Get max pins per frame
    int maxPins = 10;  // default to 10
    cout << "Enter the maximum number of pins per frame (default 10): ";
    cin >> maxPins;

    while (maxPins <= 0)
    {
        cout << "Invalid input. Enter a positive number for max pins: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> maxPins;
    }

    int noOfFrames = 0;
    cout << "Enter the total number of frames to play: ";
    cin >> noOfFrames;

    while (noOfFrames <= 0)
    {
        cout << "Invalid number. Enter a positive number for frames: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> noOfFrames;
    }

    cout << "\nStarting the game with " << numPlayers << " player(s), "
        << noOfFrames << " frames each, and max pins per frame: " << maxPins << "\n\n";

    // Loop through frames
    for (int frame = 1; frame <= noOfFrames; ++frame)
    {
        cout << "==================== Frame " << frame << " ====================\n";

        for (auto& playerInfo : m_BowlingPlayers)
        {
            Frame current;
            current.setMaxPins(maxPins);

            int first = 0, second = 0, bonus = 0;

            cout << "Player: " << playerInfo.name << "\n";

            // Input first throw 
            do
            {
                cout << "  First throw (0-" << maxPins << "): ";
                cin >> first;

                if (cin.fail() || first < 0 || first > maxPins)
                {
                    cout << "  Invalid input. Enter a number between 0 and " << maxPins << ".\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else break;
            } while (true);

            // Input second throw (if applicable)
            if (first != maxPins || frame == noOfFrames)
            {
                do
                {
                    cout << "  Second throw (0-" << maxPins << "): ";
                    cin >> second;

                    if (cin.fail() || second < 0 || second > maxPins)
                    {
                        cout << "  Invalid input. Pins must be between 0 and " << maxPins << ".\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else if (frame != noOfFrames && (first + second) > maxPins)
                    {
                        cout << "  Total pins in a frame must not exceed " << maxPins << ".\n";
                    }
                    else break;
                } while (true);
            }

            current.setThrows(first, second);

            // Bonus throw for last frame
            if (frame == noOfFrames && (current.isStrike() || current.isSpare()))
            {
                do
                {
                    cout << "  Bonus throw (0-" << maxPins << "): ";
                    cin >> bonus;

                    if (cin.fail() || bonus < 0 || bonus > maxPins)
                    {
                        cout << "  Invalid input. Pins must be between 0 and " << maxPins << ".\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else break;
                } while (true);

                current.setBonus(bonus);
            }

            playerInfo.player.addFrame(current);

            cout << endl;
        }

        // Show running scores after each frame
        cout << "Current Scores after Frame " << frame << ":\n";
        for (const auto& playerInfo : m_BowlingPlayers)
        {
            cout << "  " << playerInfo.name << ": " << playerInfo.player.totalScore() << "\n";
        }
        cout << "========================================================\n\n";
    }
}

void BowlingGame::showScore() const
{
    cout << "\nFinal Scores:\n";
    for (const auto& playerInfo : m_BowlingPlayers)
    {
        cout << playerInfo.name << ": " << playerInfo.player.totalScore() << endl;
    }
}
