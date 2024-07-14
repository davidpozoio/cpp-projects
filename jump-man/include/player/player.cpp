#include "player.h"
#include <ncurses.h>

Player::Player()
{
    playerStates.setCurrentState(JumpStates::OnFloor);
    playerStates.setState(JumpStates::Jump, {JumpStates::Jump, {{JumpStates::Falling, JumpStates::Falling}}});

    playerStates.setState(JumpStates::Falling, {JumpStates::Falling, {{JumpStates::OnFloor, JumpStates::OnFloor}}});

    playerStates.setState(JumpStates::OnFloor, {JumpStates::OnFloor, {{JumpStates::Jump, JumpStates::Jump}}});
}

void Player::print()
{
    mvprintw(0, 0, "x");
    refresh();
}
