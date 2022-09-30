// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the adapter design pattern, in which a client using weight in pounds may interact through the adapter with an interface expecting mass in kilograms

# include "Adapter.h"

// Define print functionality for mass (available through Mass interface)
void Mass::getMass() { std::cout << entity_mass << std::endl; }

// Define print functionality for mass (available through adapter interface)
void weightAdapter::getWeight() { getMass(); }

int main(int argc, char *argv[]) {

    std::cout << "Adapter design pattern test" << std::endl;

    // UPDATE WITH FINISHED TEMPLATES

    // Client interacts with Weight interface through weightAdapter initilized with weight in lbs. 
    int value = 30;
    std::unique_ptr<Weight> w(new weightAdapter(value)); 
    
    // Calling the getWeight function shows that a mass value is now available to the incompatible Mass interface
    w->getWeight();    

    return 0;

}
