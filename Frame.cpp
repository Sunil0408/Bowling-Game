// Frame.cpp
#include "Frame.h"
#include <string>
using namespace std;

Frame::Frame()
{
    first = 0;
    second = 0;
    bonus = 0;
    hasBonus = false;
    maxPins = 0;
}

void Frame::setThrows(int f, int s) 
{
    if (f < 0 || f > maxPins || s < 0 || s > maxPins)
    {
        throw std::invalid_argument("Pins must be between 0 and " + std::to_string(maxPins));
    }
    if (f != maxPins && (f + s > maxPins))
    {
        throw invalid_argument("Total pins can't be more than "+ std::to_string(maxPins) + " unless first is strike.");
    }
    //set first and second throw value 
    first = f;
    second = s;
}
void Frame::setMaxPins(int m)
{
    maxPins = m;
}
void Frame::setBonus(int b) 
{
    if (b < 0 || b > maxPins)
    {
        throw invalid_argument("Bonus pins must be between 0 and " + std::to_string(maxPins));
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
    //strike is when first throw itself is euqal to maxPins
    return first == maxPins;
}

bool Frame::isSpare() const 
{
    //Spare is when first throw is not equal to maxPins and sum is equal to maxPins
    return (first + second == maxPins) && first != maxPins;
}

