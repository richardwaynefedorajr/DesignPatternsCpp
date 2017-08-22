# include <iostream>
# include <string>

class Hundred;
class Ten;
class One;

class Interpreter {
    public:
        Interpreter();
        Interpreter(int *dummy) { }
        void interpret(int number);
        virtual void interpret();
        void setInput(int input);
    private:
        Hundred *m_hundred;
        Ten *m_ten;
        One *m_one;
        int m_value;
        int m_input;
};

class Hundred : public Interpreter {
    public:
        Hundred(int *dummy) : Interpreter(NULL) { }
        int interpret(int number); 
        std::string m_hundreds;
};

class Ten : public Interpreter {
    public:
        Ten(int *dummy) : Interpreter(NULL) { }
        int interpret(int number);
        std::string m_tens; 
};

class One : public Interpreter {
    public:
        One(int *dummy) : Interpreter(NULL) { }
        int interpret(int number); 
        std::string m_ones;
};
