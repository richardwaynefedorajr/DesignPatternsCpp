# include "FunctionPointers.h"

// Define functor operator overload
void FunctorClass::operator()() const { std::cout << "Functor call output" << std::endl; }

// Define standalone function
void testFunction(std::string input) {
    std::cout << "Function call output: input = " << input << std::endl;
};

// Define class with member, method and const method
classMemberMethod::classMemberMethod(std::string input) : m_string(input) { }
void classMemberMethod::memberMethod(std::string input) { 
    std::cout << "Class member method call ouput: method input = " << input << std::endl;
}
