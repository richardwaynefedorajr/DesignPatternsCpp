// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the prototype design pattern, in which a factory class maintains a set of prototype instances of a derived class which clone themselves to produce additional instances

# include "Prototype.h"

// Define factory class: initialize derived prototype instances
Factory::Factory() {
    m_A1 = std::unique_ptr<A>( new A1 );
    m_A2 = std::unique_ptr<A>( new A2 );
    m_A3 = std::unique_ptr<A>( new A3 );
}

// Define factory method to create additional instances of derived prototype classes
std::unique_ptr<A> Factory::getA(Type type) {
    switch ( type ) {
        case TYPEA1:
            return m_A1->clone();
        case TYPEA2:
            return m_A2->clone();
        case TYPEA3:
            return m_A3->clone();
    }
}

// Define derived prototype class methods: return new instance of self
std::unique_ptr<A> A1::clone() { return std::move( std::unique_ptr<A> ( new A1 ) ); }
void A1::action() { std::cout << "A1 action" << std::endl; }

std::unique_ptr<A> A2::clone() { return std::move( std::unique_ptr<A> ( new A2 ) ); }
void A2::action() { std::cout << "A2 action" << std::endl; }

std::unique_ptr<A> A3::clone() { return std::move( std::unique_ptr<A> ( new A3 ) ); }
void A3::action() { std::cout << "A3 action" << std::endl; }
