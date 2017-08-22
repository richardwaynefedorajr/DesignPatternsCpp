# include <iostream>
# include <string>
# include <memory>

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
        std::unique_ptr<Hundred> m_hundred;
        std::unique_ptr<Ten> m_ten;
        std::unique_ptr<One> m_one;
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
