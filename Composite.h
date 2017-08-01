# include <vector>
# include <iostream>
# include <string>

class Lure {
    public:
        virtual void getLure() = 0;
};

class SingleLure : public Lure {
    std::string m_name;
    public:
        SingleLure(std::string name);
        void getLure();
};

class TackleBox : public Lure {
    std::vector < Lure* > m_tacklebox;
    public:
        void addLure(Lure* lure);
        void getLure();
};
