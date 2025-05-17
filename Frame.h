// Frame.h
#pragma once
#include <stdexcept>

class Frame 
{
private:
    int first;
    int second;
    int bonus;
    bool hasBonus;

public:
    Frame();

    void setThrows(int f, int s);
    void setBonus(int b);

    int getFirst() const;
    int getSecond() const;
    int getBonus() const;
    bool bonusAvailable() const;

    bool isStrike() const;
    bool isSpare() const;
};
