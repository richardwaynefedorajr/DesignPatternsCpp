// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the prototype design pattern, in which a factory class maintains a set of prototype instances of a derived class which clone themselves to produce additional instances

# include <string>
# include <iostream>
# include <vector>
# include <memory>

// Declare enums corresponding to derived prototypes
enum Type { TYPEA1, TYPEA2, TYPEA3 };

// Declare base prototype class
class A {
    public:
        virtual std::unique_ptr<A> clone() = 0;
        virtual void action() = 0;
};

// Declare derived prototype classes
class A1 : public A {
    public:
        std::unique_ptr<A> clone();
        void action();
};

class A2 : public A {
    public:
        std::unique_ptr<A> clone();
        void action();
};

class A3 : public A {
    public:
        std::unique_ptr<A> clone();
        void action();
};

// Declare factory class to maintain prototype instances 
class Factory {
    public:
        Factory();
        std::unique_ptr<A> getA(Type type);
    private:
        std::unique_ptr<A> m_A1;
        std::unique_ptr<A> m_A2;
        std::unique_ptr<A> m_A3;
};
