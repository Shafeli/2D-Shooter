#pragma once

#include <memory>
#include <stack>
#include "State.h"

namespace Machine
{
    using StateRef = std::unique_ptr<State>;
}
class StateMachine
{
private:
    std::stack<Machine::StateRef> m_states;
    Machine::StateRef m_newState;

    bool m_isRemoving;
    bool m_isAdding;
    bool m_isReplacing;

public:

    void AddState(Machine::StateRef newState, bool isReplacing = true);
    void RemoveState();
    void ProcessStateChanges();
    Machine::StateRef& GetActiveState();


};


