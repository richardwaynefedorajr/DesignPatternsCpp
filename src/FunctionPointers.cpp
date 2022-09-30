// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description:
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

int main(int argc, char *argv[]) {
   
    std::cout << "Test function pointer cases:" << std::endl;

    // Test free function
    std::function<void(std::string)> freeFunction = testFunction;
    freeFunction("free function input");

    // Test lambda
    int i = 0, j = 0;
    std::function<void(int,int)> lambdaFunction = [&](int i, int j) { 
        std::cout << "Values: " << i << " " << j << std::endl; 
    };

    lambdaFunction(i,j);

    // Test std::bind
    std::function<void()> bindFunction = std::bind(testFunction, "std::bind input");
    bindFunction();

    // Test member function
    std::function<void(classMemberMethod&, std::string)> memberFunction = &classMemberMethod::memberMethod;
    classMemberMethod Class1("Class1 input");
    memberFunction(Class1, "Class1 member method input");
    
    // Test functor
    std::function<void()> functorFunction = FunctorClass();
    functorFunction();

    return 0;

}
