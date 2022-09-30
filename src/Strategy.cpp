// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the strategy design pattern, in which the algorithms for generating common mathematical sequences are encapsulated in derived classes and passed to a client interface class

# include "Strategy.h"

// Define interface and derived strategy constructors
Interface::Interface() : m_strategy(NULL) { }
Fibonacci::Fibonacci() : Sequence() { m_name = "Fibonacci"; }
Triangle::Triangle() : Sequence() { m_name = "Triangle"; }
Square::Square() : Sequence() { m_name = "Square"; }

// Define method for client to set strategy
void Interface::setStrategy(Sequence *strategy) { m_strategy = strategy; }

// Define method for client to use strategy
void Interface::getSequence(int num_elem) { 
    m_strategy->generateSequence(num_elem, m_sequence);
    std::cout << "First " << num_elem << " elements of the " << m_strategy->m_name << " Sequence: ";
    for ( int i = 0; i < m_sequence.size(); ++i ) {
        std::cout << m_sequence.at(i) << " ";
    }
    std::cout << std::endl;
    m_sequence.clear();
}

// Define derived strategy implementations
void Fibonacci::generateSequence(int num_elem, std::vector<int> &sequence) { 
    static int num_iter = 0;
    while ( num_iter <= num_elem ) {
        if ( sequence.size() < 2 ) { sequence.push_back(1); }
        else { sequence.push_back( sequence.at(num_iter - 1) + sequence.at(num_iter - 2) ); }
        ++num_iter;
        Fibonacci::generateSequence(num_elem, sequence); 
    }
}

void Triangle::generateSequence(int num_elem, std::vector<int> &sequence) {
    static int num_iter = 0;
    while ( num_iter <= num_elem ) {
        if ( sequence.empty() ) { sequence.push_back(1); }
        else { sequence.push_back( sequence.at(num_iter - 1) + num_iter + 1 ); }
        ++num_iter;
        Triangle::generateSequence(num_elem, sequence); 
    }
}

void Square::generateSequence(int num_elem, std::vector<int> &sequence) { 
    for ( int i = 0; i < num_elem; ++i ) {
        sequence.push_back( (i+1)*(i+1) );
    }
}

int main(int argc, char *argv[]) {
   
    std::cout << "Strategy design pattern test:" << std::endl;

    Interface i;
    Fibonacci f;
    Triangle t;
    Square s;
    i.setStrategy(&s);
    i.getSequence(10); 

    return 0;

} 
