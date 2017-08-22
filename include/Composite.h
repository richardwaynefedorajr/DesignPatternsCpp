# include <vector>
# include <iostream>
# include <string>
# include <memory>

class CompositeLure {
    public:
        virtual void getLure() = 0;
        virtual void addLure(std::unique_ptr<CompositeLure> lure) = 0;
};

class SingleLure : public CompositeLure {
    public:
        std::string m_name;
        SingleLure(std::string name);
        void getLure();
        void addLure(std::unique_ptr<CompositeLure> lure) { }
};

class TackleBox : public CompositeLure {
    public:
        std::vector < std::unique_ptr<CompositeLure> > m_tacklebox;
        void addLure(std::unique_ptr<CompositeLure> lure);
        void getLure();
};
