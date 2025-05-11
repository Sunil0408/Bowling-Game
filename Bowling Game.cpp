#include <iostream>
#include <stdexcept>
#include <thread> 
#include "Frame.h"       // For the Frame class
#include "Player.h"      // For the Player class
#include "BowlingGame.h" // For the BowlingGame class
using namespace std;

int main()
{
    try {
        BowlingGame game;
        game.run();
        game.showScore();
    }
    catch (const exception& ex) 
    {
        cerr << "Error Occured ---- " << ex.what() << endl;
    }

    cout << "\nProgram will exit in 5 seconds..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5)); 

    return 0;
}
