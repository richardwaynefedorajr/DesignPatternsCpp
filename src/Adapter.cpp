# include "Adapter.h"

// Define print functionality for mass (available through Mass interface)
void Mass::getMass() { std::cout << entity_mass << std::endl; }

// Define print functionality for mass (available through adapter interface)
void weightAdapter::getWeight() { getMass(); }
