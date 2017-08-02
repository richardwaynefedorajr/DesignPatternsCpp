# include "Prototype.h"

Factory::Factory() {
    m_A1 = new A1;
    m_A2 = new A2;
    m_A3 = new A3;
}

A* Factory::getA(Type type) {
    switch ( type ) {
        case TYPEA1:
            return m_A1->clone();
        case TYPEA2:
            return m_A2->clone();
        case TYPEA3:
            return m_A3->clone();
    }
}

A* A1::clone() { return new A1; }
void A1::action() { std::cout << "A1 action" << std::endl; }

A* A2::clone() { return new A2; }
void A2::action() { std::cout << "A2 action" << std::endl; }

A* A3::clone() { return new A3; }
void A3::action() { std::cout << "A3 action" << std::endl; }
