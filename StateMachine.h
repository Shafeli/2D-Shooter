#pragma once

#include <memory>
#include <stack>
#include "State.h"


using StateRef = std::unique_ptr<State>;

class StateMachine
{
private:
    std::stack<StateRef> m_states;
    StateRef m_newState;

    bool m_isRemoving;
    bool m_isAdding;
    bool m_isReplacing;

public:

    void AddState(StateRef newState, bool isReplacing = true);
    void RemoveState();
    void ProcessStateChanges();
    StateRef& GetActiveState();


};


