# include "Composite.h"

SingleLure::SingleLure(std::string name) : m_name(name) { }
void SingleLure::getLure() { std::cout << "Lure type: " << m_name << std::endl; }

void TackleBox::addLure(Lure* lure) { m_tacklebox.push_back(lure); }
void TackleBox::getLure() { 

    for (int i = 0; i < m_tacklebox.size(); ++i) { m_tacklebox.at(i)->getLure(); }

}
