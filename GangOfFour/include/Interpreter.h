// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the interpreter design pattern, in which the rules to translate an integer into text are distributed accross derived interpreter subclasses

# include <iostream>
# include <string>
# include <memory>

class Hundred;
class Ten;
class One;

// Declare base interpreter class to manage derived classes for parsing inputs
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

// Declare derived interpreter classes for parsing
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
