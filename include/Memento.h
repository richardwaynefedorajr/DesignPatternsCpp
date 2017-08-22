# include <string>
# include <iostream>
# include <vector>
# include <memory>

// Declaration of struct storing an individual's body measurements
struct State {
    int m_height;
    int m_weight;
    double m_bmi;
    double m_bodyfat;
};

class Memento;

// Declaration of class to store and traverse states of individual's body measurements 
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

// Declaration of class to encapsulate mementos of Person class states
class Memento {
    public:
        Memento(State state);
        State getState();
    private:
        State m_state;
};