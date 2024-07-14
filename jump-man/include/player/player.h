#include "../machine-state/machine-utils.h"

#pragma once

class Player
{
public:
    enum JumpStates
    {
        OnFloor = 0,
        Jump = 1,
        Falling = 2,
    };

    void print();
    Player();
    void move(JumpStates state);

private:
    int x = 0;
    int y = 0;

    StateMachine<JumpStates, JumpStates, JumpStates> playerStates;
};