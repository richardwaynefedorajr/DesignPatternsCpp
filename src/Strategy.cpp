# include "Strategy.h"

Interface::Interface() : m_strategy(NULL) { }
Fibonacci::Fibonacci() : Sequence() { m_name = "Fibonacci"; }
Triangle::Triangle() : Sequence() { m_name = "Triangle"; }
Square::Square() : Sequence() { m_name = "Square"; }

void Interface::setStrategy(Sequence *strategy) { m_strategy = strategy; }

void Interface::getSequence(int num_elem) { 
    m_strategy->generateSequence(num_elem, m_sequence);
    std::cout << "First " << num_elem << " elements of the " << m_strategy->m_name << " Sequence: ";
    for ( int i = 0; i < m_sequence.size(); ++i ) {
        std::cout << m_sequence.at(i) << " ";
    }
    std::cout << std::endl;
    m_sequence.clear();
}

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
