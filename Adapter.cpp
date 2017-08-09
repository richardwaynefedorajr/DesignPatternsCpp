# include "Adapter.h"

// Print entity mass (available through Mass interface)
void Mass::getMass() { std::cout << entity_mass << std::endl; }

// Print mass available through Mass interface
void weightAdapter::getWeight() { getMass(); }
