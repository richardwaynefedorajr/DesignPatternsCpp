// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description:
# include "PointerVariations.h"

TestPointer::TestPointer(std::unique_ptr<int> unique_value, std::shared_ptr<int> shared_value, int *value) {
    m_unique_int = std::move(unique_value);
    m_shared_int = shared_value;
    m_int = value;
}

void TestPointer::printPointers() {
    std::cout << "Unique pointer location: " << m_unique_int.get() << " value: " << *m_unique_int << std::endl;
    std::cout << "Shared pointer location: " << m_shared_int.get() << " value: " << *m_shared_int << std::endl;
    std::cout << "Raw pointer location: " << m_int << " value: " << *m_int << std::endl;
}

int main(int argc, char *argv[]) {
   
    std::cout << "std pointer variations test:" << std::endl;

    // Create scope to see what happens when things go out of scope
    
    std::unique_ptr<int> unique_value( new int(1) );
    std::shared_ptr<int> shared_value( new int(2) );
    std::cout << "Shared pointer location: " << shared_value.get() << " value: " << *shared_value << " usage count: " << shared_value.use_count() << std::endl;
    int *value = new int(3);

    {

        TestPointer tp1( std::unique_ptr<int> (new int(1) ), std::shared_ptr<int> (new int(2) ), new int(3) );
               
        TestPointer tp2(std::move(unique_value), shared_value, value);

        std::cout << "Pointers initialized in argument:" << std::endl;
        tp1.printPointers();
        std::cout << "Pointers initialized outside of class and passed as arguments:" << std::endl;
        tp2.printPointers();

        // Check for dangling pointers
        if (unique_value.get()) {
            std::cout << "Unique pointer location: " << unique_value.get() << " value: " << *unique_value << std::endl;
        }
        else { std::cout << "Unique ptr is now nullptr: watch out for dangling pointers!" << std::endl; }
        std::cout << "Shared pointer location: " << shared_value.get() << " value: " << *shared_value << " usage count: " << shared_value.use_count() << std::endl;
        std::cout << "Raw pointer location: " << value << " value: " << *value << std::endl;

    }

    if (unique_value.get()) {
        std::cout << "Unique pointer location: " << unique_value.get() << " value: " << *unique_value << std::endl;
    }
    else { std::cout << "Unique ptr is now nullptr: watch out for dangling pointers!" << std::endl; }
    std::cout << "Shared pointer location: " << shared_value.get() << " value: " << *shared_value << " usage count: " << shared_value.use_count() << std::endl;
    std::cout << "Raw pointer location: " << value << " value: " << *value << std::endl;


    // Potential memory leak -> TestPointer class does not manage resource, just maintains pointer 
    delete value; 

    return 0;

}
