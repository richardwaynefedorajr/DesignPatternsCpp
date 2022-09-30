// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description:
# include "Composite.h"

// Define functionality for "single" derived class
SingleLure::SingleLure(std::string name) : m_name(name) { }
void SingleLure::getLure() { std::cout << "Lure type: " << m_name << " "; }

// Define functionality for composite derived class
void TackleBox::addLure(std::unique_ptr<CompositeLure> lure) { m_tacklebox.push_back( std::move(lure) ); }
void TackleBox::getLure() { 
    for (int i = 0; i < m_tacklebox.size(); ++i) { m_tacklebox.at(i)->getLure(); }
}

int main(int argc, char *argv[]) {
   
    std::cout << "Composite design pattern test:" << std::endl;

    std::vector<std::string> names;
    names.push_back("Jig");
    names.push_back("Soft plastic");
    names.push_back("Spinnerbait");
    names.push_back("Crankbait");

    int num_lure_types = names.size();

    std::vector< std::unique_ptr<CompositeLure> > box;

    for (int i = 0; i < num_lure_types; ++i) { 
        box.push_back( std::unique_ptr<CompositeLure>( new TackleBox() ) ); 
    }
    
    for (int i = 0; i < num_lure_types; ++i) { 
        box.at(i)->addLure( std::unique_ptr<CompositeLure>( new SingleLure(names.at(i)) ) ); 
    }
    
    for (int i = 1; i < num_lure_types; ++i) { 
        box.at(0)->addLure( std::unique_ptr<CompositeLure>( new SingleLure(names.at(i)) ) ); 
    }

    
    for (int i = 0; i < num_lure_types; ++i) { box.at(i)->getLure(); std::cout << std::endl; }

    return 0;

}
