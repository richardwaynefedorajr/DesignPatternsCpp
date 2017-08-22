# include "Bridge.h"

Color::Color(std::string in_color) { m_color = in_color; }
Weight::Weight(std::string in_weight) { m_weight = in_weight; }
Length::Length(std::string in_length) { m_length = in_length; }
Depth::Depth(std::string in_depth) { m_depth = in_depth; }

std::string Color::getCharacteristic() { return m_color; }
std::string Weight::getCharacteristic() { return m_weight; }
std::string Length::getCharacteristic() { return m_length; }
std::string Depth::getCharacteristic() { return m_depth; }

void LeadJig::getLure() { std::cout << m_weight->getCharacteristic() << " " << m_color->getCharacteristic() << " " << "jig" << std::endl; }

void PlasticSoft::getLure() { std::cout << m_color->getCharacteristic() << " " << m_length->getCharacteristic() << " " << "soft plastic" << std::endl; }

void Crankbait::getLure() { std::cout << m_length->getCharacteristic() << " " << m_color->getCharacteristic() << " " << m_depth->getCharacteristic() << " " << "crankbait" << std::endl; }

void Spinnerbait::getLure() { std::cout << m_weight->getCharacteristic() << " " << m_color->getCharacteristic() << " " << "spinnerbait" << std::endl; }
