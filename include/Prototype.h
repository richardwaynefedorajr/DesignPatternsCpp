# include <string>
# include <iostream>
# include <vector>
# include <memory>

enum Type { TYPEA1, TYPEA2, TYPEA3 };

class A {
    public:
        virtual std::unique_ptr<A> clone() = 0;
        virtual void action() = 0;
};

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

class Factory {
    public:
        Factory();
        std::unique_ptr<A> getA(Type type);
    private:
        std::unique_ptr<A> m_A1;
        std::unique_ptr<A> m_A2;
        std::unique_ptr<A> m_A3;
};
