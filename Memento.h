# include <string>
# include <iostream>
# include <vector>

struct State {
    int m_height;
    int m_weight;
    double m_bmi;
    double m_bodyfat;
};

class Memento;

class Person {
    public:
        Person();
        ~Person();
        void setMemento();
        void backState();
        void forwardState();
        void setState(int height, int weight, double bmi, double bodyfat);
        void printState(); 
    private:
        State m_state;
        std::vector<Memento*> m_history;
        int m_index;
};

class Memento {
    public:
        Memento(State state);
        State getState();
    private:
        State m_state;
};
