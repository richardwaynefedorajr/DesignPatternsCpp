// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the adapter design pattern, in which a client using weight in pounds may interact through the adapter with an interface expecting mass in kilograms

# include <iostream>
# include <memory>

// Declare gravitational constant
# define M_G 9.81

// Declare interface for weight of an entity 
class Weight {
    public:
        virtual void getWeight() = 0;
};

// Declare incompatible class for mass of entity
class Mass {
    public:
        template<typename T>
        Mass(T m) { entity_mass = m; }
        void getMass();

    private:
        double entity_mass;
};

// Declare adapter to allow client expecting Weight to interact with Mass interface
class weightAdapter : public Weight, private Mass {
    public:
        template<typename T>
        weightAdapter(T w) : Mass(w/M_G ) { std::cout << "Mass value returned for weight = " << w << ": "; }
        virtual void getWeight();
};
