// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description
# include <vector>
# include <iostream>
# include <string>
# include <memory>

// Declare base class
class CompositeLure {
    public:
        virtual void getLure() = 0;
        virtual void addLure(std::unique_ptr<CompositeLure> lure) = 0;
};

// Declare "single" derived class
class SingleLure : public CompositeLure {
    public:
        std::string m_name;
        SingleLure(std::string name);
        void getLure();
        void addLure(std::unique_ptr<CompositeLure> lure) { }
};

// Declare composite derived class
class TackleBox : public CompositeLure {
    public:
        std::vector < std::unique_ptr<CompositeLure> > m_tacklebox;
        void addLure(std::unique_ptr<CompositeLure> lure);
        void getLure();
};
