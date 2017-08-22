# include <string>
# include <iostream>

class LureVisitor;

class Fish {
    public:
        Fish() { }
        virtual void seeLure(LureVisitor &lure) = 0;
        std::string m_species;
};

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

// Visitor
class LureVisitor {
    public:
        LureVisitor() { }
        virtual void present(Bass *bass) = 0;
        virtual void present(Trout *trout) = 0;
        virtual void present(Musky *musky) = 0;
        std::string m_name;
};

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
