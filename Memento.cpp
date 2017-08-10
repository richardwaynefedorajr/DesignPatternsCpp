# include "Memento.h"

// Set and get mementos of state
Memento::Memento(State state) { m_state = state; }
State Memento::getState() { return m_state; }

// Initialize state in constructor
Person::Person() { 
    m_index = -1;
    m_state.m_height = 0;
    m_state.m_weight = 0;
    m_state.m_bmi = 0.0;
    m_state.m_bodyfat = 0.0;
    setMemento();
}

// Traverse stored mementos, set and get state
// Note: if previous states are returned to and a new state is set, states which were saved before the regression will be deleted
void Person::setMemento() { m_history.push_back( std::unique_ptr<Memento>( new Memento(m_state) ) ); ++m_index; }
void Person::backState() { 
    if ( m_index > 1 ) { m_state = m_history.at(--m_index)->getState(); }
    else { std::cout << "Attempt to back overrun stored states!" << std::endl; }

}
void Person::forwardState() { 
    if ( m_index < m_history.size() - 1 ) { m_state = m_history.at(++m_index)->getState(); }
    else { std::cout << "Attempt to forward overrun stored states!" << std::endl; }
}

void Person::setState(int height, int weight, double bmi, double bodyfat) {
    m_state.m_height = height;
    m_state.m_weight = weight;
    m_state.m_bmi = bmi;
    m_state.m_bodyfat = bodyfat;
    while ( m_history.size() > m_index + 1 ) { m_history.pop_back(); }
    setMemento();
}

void Person::printState() {
    std::cout << "Height: " << m_state.m_height << " ";
    std::cout << "Weight: " << m_state.m_weight << " ";
    std::cout << "BMI: " << m_state.m_bmi << " ";
    std::cout << "Bodyfat: " << m_state.m_bodyfat << std::endl;
    std::cout << "Index: " << m_index << " Mementos: " << m_history.size() << std::endl;
}
