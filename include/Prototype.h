# include <string>
# include <iostream>
# include <vector>

enum Type { TYPEA1, TYPEA2, TYPEA3 };

class A {
    public:
        virtual A *clone() = 0;
        virtual void action() = 0;
};

class A1 : public A {
    public:
        A *clone();
        void action();
};

class A2 : public A {
    public:
        A *clone();
        void action();
};

class A3 : public A {
    public:
        A *clone();
        void action();
};

class Factory {
    public:
        Factory();
        A *getA(Type type);
    private:
        A1 *m_A1;
        A2 *m_A2;
        A3 *m_A3;
};
