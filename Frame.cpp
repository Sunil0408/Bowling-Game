// Frame.cpp
#include "Frame.h"
using namespace std;

Frame::Frame()
{
    first = 0;
    second = 0;
    bonus = 0;
    hasBonus = false;
}

void Frame::setThrows(int f, int s) 
{
    if (f < 0 || f > 10 || s < 0 || s > 10) 
    {
        throw invalid_argument("Pins must be between 0 and 10.");
    }
    if (f != 10 && (f + s > 10)) 
    {
        throw invalid_argument("Total pins can't be more than 10 unless first is strike.");
    }
    //set first and second throw value 
    first = f;
    second = s;
}

void Frame::setBonus(int b) 
{
    if (b < 0 || b > 10) 
    {
        throw invalid_argument("Bonus pins must be between 0 and 10.");
    }
    //set bonus value and make flag as true
    bonus = b;
    hasBonus = true;
}

int Frame::getFirst() const 
{
    return first;
}

int Frame::getSecond() const 
{
    return second;
}

int Frame::getBonus() const 
{
    return bonus;
}

bool Frame::bonusAvailable() const 
{
    return hasBonus;
}

bool Frame::isStrike() const 
{
    //strike is when first throw itself is 10
    return first == 10;
}

bool Frame::isSpare() const 
{
    //Spare is when first throw is not 10 and sum is equal to 10
    return (first + second == 10) && first != 10;
}
