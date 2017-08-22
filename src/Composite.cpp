# include "Composite.h"

SingleLure::SingleLure(std::string name) : m_name(name) { }
void SingleLure::getLure() { std::cout << "Lure type: " << m_name << " "; }

void TackleBox::addLure(std::unique_ptr<CompositeLure> lure) { m_tacklebox.push_back( std::move(lure) ); }
void TackleBox::getLure() { 
    for (int i = 0; i < m_tacklebox.size(); ++i) { m_tacklebox.at(i)->getLure(); }
}
