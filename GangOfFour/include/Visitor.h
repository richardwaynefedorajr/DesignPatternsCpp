// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the visitor design pattern, in which a visitor lure class "visits" a fish class and either catches or does not catch them depending on the derived class of each

# include <string>
# include <iostream>
# include <vector>
# include <memory>

class LureVisitor;

// Declaration of visited base element (pure virtual method accepts reference to visitor object as argument)
class Fish {
    public:
        Fish() { }
        virtual void seeLure(LureVisitor &lure) = 0;
        std::string m_species;
};

// Declare derived visited elements
class Bass : public Fish {
    public: 
        Bass();
        void seeLure(LureVisitor &lure);
};

class Trout : public Fish {
    public: 
        Trout();
        void seeLure(LureVisitor &lure);
};

class Musky : public Fish {
    public: 
        Musky();
        void seeLure(LureVisitor &lure);
};

// Declare visitor base class (pure virtual method overloaded to accept pointer to each derived visited element)
class LureVisitor {
    public:
        LureVisitor() { }
        virtual void present(Bass *bass) = 0;
        virtual void present(Trout *trout) = 0;
        virtual void present(Musky *musky) = 0;
        std::string m_name;
};

// Declare derived visitor classes
class Jig : public LureVisitor {
    public:
        Jig();
        void present(Bass *bass);
        void present(Trout *trout);
        void present(Musky *musky);
};

class Fly : public LureVisitor {
    public:
        Fly();
        void present(Bass *bass);
        void present(Trout *trout);
        void present(Musky *musky);
};

class Plug : public LureVisitor {
    public:
        Plug();
        void present(Bass *bass);
        void present(Trout *trout);
        void present(Musky *musky);
};
