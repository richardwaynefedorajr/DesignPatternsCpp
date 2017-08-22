# include "Visitor.h"

Bass::Bass() : Fish() { m_species = "Bass"; }
Trout::Trout() : Fish() { m_species = "Trout"; }
Musky::Musky() : Fish() { m_species = "Musky"; }

Jig::Jig() : LureVisitor() { m_name = "Jig"; }
Fly::Fly() : LureVisitor() { m_name = "Fly"; }
Plug::Plug() : LureVisitor() { m_name = "Plug"; }

void Bass::seeLure(LureVisitor &lure) { lure.present(this); }
void Trout::seeLure(LureVisitor &lure) { lure.present(this); }
void Musky::seeLure(LureVisitor &lure) { lure.present(this); }

void Jig::present(Bass *bass) { std::cout << bass->m_species << " strikes " << m_name << std::endl; }
void Jig::present(Trout *trout) { std::cout << trout->m_species << " does not strike " << m_name << std::endl; }
void Jig::present(Musky *musky) { std::cout << musky->m_species << " does not strike " << m_name << std::endl; }

void Fly::present(Bass *bass) { std::cout << bass->m_species << " does not strike " << m_name << std::endl; }
void Fly::present(Trout *trout) { std::cout << trout->m_species << " strikes " << m_name << std::endl; }
void Fly::present(Musky *musky) { std::cout << musky->m_species << " does not strike " << m_name << std::endl; }

void Plug::present(Bass *bass) { std::cout << bass->m_species << " does not strike " << m_name << std::endl; }
void Plug::present(Trout *trout) { std::cout << trout->m_species << " does not strike " << m_name << std::endl; }
void Plug::present(Musky *musky) { std::cout << musky->m_species << " strikes " << m_name << std::endl; }
