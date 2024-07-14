#include <map>

#pragma once

template <typename Output, typename Input, typename States>
class StateMachine
{
    struct State
    {
        Output output;
        std::map<Input, Output, States> next;
    };
    States currentState;
    std::map<States, State> stateMachine;

public:
    setCurrentState(States currentState)
    {
        this->currentState = currentState;
    }
    void setState(States state, State transtion)
    {
        stateMachine[state] = transtion;
    }

    State getCurrentState()
    {
        return stateMachine[currentState];
    }

    void next(Input input)
    {
        auto it = this->stateMachine[this->currentState].next.find(input);

        if (it == this->stateMachine[this->currentState].next.end())
        {
            return;
        }

        this->currentState = this->stateMachine[this->currentState].next[input];
    }
};