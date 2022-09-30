// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the state design pattern, in which states are represented in derived classes owned by a member pointer of the subject class

# include "State.h"

// Define wrapper functionality to get, set, and delegate to state instances (passing pointer to self in the case of delegation)
void Subject::setState(std::unique_ptr<State> state) { m_state = std::move(state); }
void Subject::state1() { m_state->state1(this); }
void Subject::state2() { m_state->state2(this); }
void Subject::state3() { m_state->state3(this); }
void Subject::getState() { std::cout << m_state->m_state << std::endl; }

// Define derived state class constructors
State1::State1() : State() {
    m_state = "State 1";
}

State2::State2() : State() {
    m_state = "State 2";
}

State3::State3() : State() {
    m_state = "State 3";
}

// Define base state class methods (may be overriden by derived classes, accepts pointer to wrapper as argument)
void State::state1(Subject *subject) { subject->getState(); }
void State::state2(Subject *subject) { subject->getState(); }
void State::state3(Subject *subject) { subject->getState(); }

// Define derived state class overridden methods
void State1::state2(Subject *subject) {
    std::cout << "Switching to ";
    subject->setState(std::unique_ptr<State>( new State2() ) );
    subject->getState();
}

void State2::state3(Subject *subject) {
    std::cout << "Switching to ";
    subject->setState(std::unique_ptr<State>( new State3() ) );
    subject->getState();
}

void State3::state1(Subject *subject) {
    std::cout << "Switching to ";
    subject->setState(std::unique_ptr<State>( new State1() ) );
    subject->getState();
}

int main(int argc, char *argv[]) {
   
    std::cout << "State design pattern test:" << std::endl;

    Subject s;
    s.setState( std::unique_ptr<State>( new State1() ) );
    s.m_state->state1(&s);
    s.m_state->state2(&s);
    s.m_state->state3(&s);
    s.m_state->state1(&s);
    s.m_state->state2(&s);
    s.m_state->state3(&s);
    
    return 0;

} 
