# include <vector>
# include <iostream>
# include <string>
# include <memory>

class Lure {
    public:
        virtual void getLure() = 0;
};

class SingleLure : public Lure {
    public:
        std::string m_name;
        SingleLure(std::string name);
        void getLure();
};

class TackleBox : public Lure {
    public:
        std::vector < Lure* > m_tacklebox;
        void addLure(Lure* lure);
        void getLure();
};
