# include <iostream>
# include <vector>

// Declare base strategy class
class Sequence {
    public:
        Sequence() { }
        virtual void generateSequence(int num_elem, std::vector<int> &sequence) = 0;
        std::string m_name;
};

// Declare interface class accessible to client
class Interface {
    public:
        Interface();
        void setStrategy(Sequence *strategy);
        void getSequence(int num_elem);
    private:
        Sequence *m_strategy;
        std::vector<int> m_sequence;
};

// Declare derived strategy classes
class Fibonacci : public Sequence {
    public:
        Fibonacci();
        void generateSequence(int num_elem, std::vector<int> &sequence);
};

class Triangle : public Sequence {
    public:
        Triangle();
        void generateSequence(int num_elem, std::vector<int> &sequence);
};

class Square : public Sequence {
    public:
        Square();
        void generateSequence(int num_elem, std::vector<int> &sequence);
};
