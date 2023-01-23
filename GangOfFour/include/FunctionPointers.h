// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description
# include <iostream>
# include <utility>
# include <functional>

// Declare functor
class FunctorClass {
    public:
        void operator()() const;
};

// Declare function
void testFunction(std::string input);

// Declare a class with member, method, and const method
class classMemberMethod {
    public:
        classMemberMethod(std::string input);
        void memberMethod(std::string input);
        std::string m_string;
};

