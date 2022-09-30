// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the bridge design pattern, in which the interface and implementation specifics for creating fishing lures are abstracted behind LureType and LureCharacteristic base classes

# include "Bridge.h"

// Define derived implementaion class constructors
Color::Color(std::string in_color) { m_color = in_color; }
Weight::Weight(std::string in_weight) { m_weight = in_weight; }
Length::Length(std::string in_length) { m_length = in_length; }
Depth::Depth(std::string in_depth) { m_depth = in_depth; }

// Define get functionality for derived implementation classes
std::string Color::getCharacteristic() { return m_color; }
std::string Weight::getCharacteristic() { return m_weight; }
std::string Length::getCharacteristic() { return m_length; }
std::string Depth::getCharacteristic() { return m_depth; }

// Define get functionality for abstraction interface derived classes
void LeadJig::getLure() { std::cout << m_weight->getCharacteristic() << " " << m_color->getCharacteristic() << " " << "jig" << std::endl; }

void PlasticSoft::getLure() { std::cout << m_color->getCharacteristic() << " " << m_length->getCharacteristic() << " " << "soft plastic" << std::endl; }

void Crankbait::getLure() { std::cout << m_length->getCharacteristic() << " " << m_color->getCharacteristic() << " " << m_depth->getCharacteristic() << " " << "crankbait" << std::endl; }

void Spinnerbait::getLure() { std::cout << m_weight->getCharacteristic() << " " << m_color->getCharacteristic() << " " << "spinnerbait" << std::endl; }

int main(int argc, char *argv[]) {
   
    std::cout << "Bridge design pattern test:" << std::endl;

    std::shared_ptr<LureCharacteristic> black( new Color("black") );
    std::shared_ptr<LureCharacteristic> pearl( new Color("pearl") );
    std::shared_ptr<LureCharacteristic> firetiger( new Color("firetiger") );

    std::shared_ptr<LureCharacteristic> quarter_oz( new Weight("1/4 oz.") ); 
    std::shared_ptr<LureCharacteristic> half_oz( new Weight("1/2 oz.") ); 
    std::shared_ptr<LureCharacteristic> three_quarter_oz( new Weight("3/4 oz.") ); 

    std::shared_ptr<LureCharacteristic> four_inch( new Length("4\"") );
    std::shared_ptr<LureCharacteristic> five_inch( new Length("5\"") );
    std::shared_ptr<LureCharacteristic> six_inch( new Length("6\"") );

    std::shared_ptr<LureCharacteristic> shallow( new Depth("0-4\'") );
    std::shared_ptr<LureCharacteristic> medium_depth( new Depth("4-8\'") );
    std::shared_ptr<LureCharacteristic> deep_diver( new Depth("8-12\'") );

    std::unique_ptr<LureType> big_bass_jig( new LeadJig( black, three_quarter_oz ) );
    std::unique_ptr<LureType> finesse_jig( new LeadJig( pearl, quarter_oz ) );
 
    std::unique_ptr<LureType> big_plastic( new PlasticSoft( black, six_inch ) );
    std::unique_ptr<LureType> small_plastic( new PlasticSoft( pearl, four_inch ) );

    std::unique_ptr<LureType> power_crank( new Crankbait( firetiger, six_inch, deep_diver ) );
    
    std::unique_ptr<LureType> classic_spinnerbait( new Spinnerbait( pearl, half_oz ) );

    big_bass_jig->getLure();
    finesse_jig->getLure();
    big_plastic->getLure();
    small_plastic->getLure();
    power_crank->getLure();
    classic_spinnerbait->getLure();

    return 0;

}
