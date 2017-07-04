# include "Adapter.h"

// Initialize entity mass in kg
Mass::Mass(double m) { entity_mass = m; } // kg 

// Print entity mass (available through Mass interface)
void Mass::getMass() { std::cout << entity_mass << std::endl; }

// Print weight initialized through weightAdapter interface to make conversion visible
weightAdapter::weightAdapter(double w) : Mass(w/M_G) { 
        std::cout << "Mass value returned for weight = " << w << ": ";
}

// Print mass available through Mass interface
void weightAdapter::getWeight() { getMass(); }
