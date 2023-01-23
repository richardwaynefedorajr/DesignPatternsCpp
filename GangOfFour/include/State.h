// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the state design pattern, in which states are represented in derived classes owned by a member pointer of the subject class

# include <string>
# include <iostream>
# include <memory>

class State;

// Declare wrapper class for state class 
class Subject {
    public:
        void setState(std::unique_ptr<State> state);
        void getState();
        void state1();
        void state2();
        void state3();
        std::unique_ptr<State> m_state;
};

// Declare base state class (pure virtual method accepts pointer to wrapper as argument)
class State {
    public:
        State() { }
        virtual void state1(Subject *subject);
        virtual void state2(Subject *subject);
        virtual void state3(Subject *subject);
        std::string m_state;
};

// Declare derived state classes
class State1 : public State {
    public:
        State1();
        void state2(Subject *subject);
};

class State2 : public State {
    public:
        State2();
        void state3(Subject *subject);
};

class State3 : public State {
    public:
        State3();
        void state1(Subject *subject);
};
