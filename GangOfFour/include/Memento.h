// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the memento design pattern, in which a Memento class encapsulates a "snapshot" of on object's state and provides access to previous states 

# include <string>
# include <iostream>
# include <vector>
# include <memory>

// Declare state struct
struct State {
    int m_height;
    int m_weight;
    double m_bmi;
    double m_bodyfat;
};

class Memento;

// Declare class to store and traverse state structs
class Person {
    public:
        Person();
        void setMemento();
        void backState();
        void forwardState();
        void setState(int height, int weight, double bmi, double bodyfat);
        void printState(); 
    private:
        State m_state;
        std::vector< std::unique_ptr<Memento> > m_history;
        int m_index;
};

// Declare class to encapsulate mementos of Person class states
class Memento {
    public:
        Memento(State state);
        State getState();
    private:
        State m_state;
};
