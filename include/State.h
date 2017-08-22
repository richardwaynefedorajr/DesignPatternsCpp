# include <string>
# include <iostream>

class State;

class Subject {
    public:
        ~Subject();
        void setState(State *state);
        void getState();
        void state1();
        void state2();
        void state3();
        State *m_state;
};

class State {
    public:
        State() { }
        virtual void state1(Subject *subject);
        virtual void state2(Subject *subject);
        virtual void state3(Subject *subject);
        std::string m_state;
};

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
