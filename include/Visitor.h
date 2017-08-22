# include <string>
# include <iostream>

class Lure;

class Fish {
    public:
        Fish() { }
        virtual void seeLure(Lure &lure) = 0;
        std::string m_species;
};

class Bass : public Fish {
    public: 
        Bass();
        void seeLure(Lure &lure);
};

class Trout : public Fish {
    public: 
        Trout();
        void seeLure(Lure &lure);
};

class Musky : public Fish {
    public: 
        Musky();
        void seeLure(Lure &lure);
};

// Visitor
class Lure {
    public:
        Lure() { }
        virtual void present(Bass *bass) = 0;
        virtual void present(Trout *trout) = 0;
        virtual void present(Musky *musky) = 0;
        std::string m_name;
};

class Jig : public Lure {
    public:
        Jig();
        void present(Bass *bass);
        void present(Trout *trout);
        void present(Musky *musky);
};

class Fly : public Lure {
    public:
        Fly();
        void present(Bass *bass);
        void present(Trout *trout);
        void present(Musky *musky);
};

class Plug : public Lure {
    public:
        Plug();
        void present(Bass *bass);
        void present(Trout *trout);
        void present(Musky *musky);
};
