// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the visitor design pattern, in which a visitor lure class "visits" a fish class and either catches or does not catch them depending on the derived class of each

# include "Visitor.h"

// Define constructors: initialize derived class name values
Bass::Bass() : Fish() { m_species = "Bass"; }
Trout::Trout() : Fish() { m_species = "Trout"; }
Musky::Musky() : Fish() { m_species = "Musky"; }

Jig::Jig() : LureVisitor() { m_name = "Jig"; }
Fly::Fly() : LureVisitor() { m_name = "Fly"; }
Plug::Plug() : LureVisitor() { m_name = "Plug"; }

// Define derived class inherited methods which accept reference to visitor as argument
// Call visitor funtionality by passing pointer to self to visitor accepted as argument
void Bass::seeLure(LureVisitor &lure) { lure.present(this); }
void Trout::seeLure(LureVisitor &lure) { lure.present(this); }
void Musky::seeLure(LureVisitor &lure) { lure.present(this); }

// Define overloaded derived visitor class methods: receive pointer to visited element as argument
// Called by visited element which passes pointer to itself as argument
void Jig::present(Bass *bass) { std::cout << bass->m_species << " strikes " << m_name << std::endl; }
void Jig::present(Trout *trout) { std::cout << trout->m_species << " does not strike " << m_name << std::endl; }
void Jig::present(Musky *musky) { std::cout << musky->m_species << " does not strike " << m_name << std::endl; }

void Fly::present(Bass *bass) { std::cout << bass->m_species << " does not strike " << m_name << std::endl; }
void Fly::present(Trout *trout) { std::cout << trout->m_species << " strikes " << m_name << std::endl; }
void Fly::present(Musky *musky) { std::cout << musky->m_species << " does not strike " << m_name << std::endl; }

void Plug::present(Bass *bass) { std::cout << bass->m_species << " does not strike " << m_name << std::endl; }
void Plug::present(Trout *trout) { std::cout << trout->m_species << " does not strike " << m_name << std::endl; }
void Plug::present(Musky *musky) { std::cout << musky->m_species << " strikes " << m_name << std::endl; }
