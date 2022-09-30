// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the factory design pattern, in which factory method setLure of base class Lure creates instances of child class objects (representing different types of fishing lures in a tacklebox)

# include "Factory.h"
# include <vector>

// Define constructors for derived product classes
FactoryJig::FactoryJig(std::string char1, std::string char2, std::string char3){
    weight = char1;
    head_type = char2;
    trailer_type = char3;
}

Spinner::Spinner(std::string char1, std::string char2, std::string char3){
    weight = char1;
    blade_type = char2;
    blade_pattern = char3;
}

FactoryPlug::FactoryPlug(std::string char1, std::string char2, std::string char3){
    length = char1;
    plug_type = char2;
    color_pattern = char3;
}

FactoryFly::FactoryFly(std::string char1, std::string char2, std::string char3){
    length = char1;
    tied_pattern = char2;
    color_pattern = char3;
}

SoftPlastic::SoftPlastic(std::string char1, std::string char2, std::string char3){
    length = char1;
    style = char2;
    color_pattern = char3;
}

// Define overridden methods of base product class to print product characteristics
void FactoryJig::getLure() { std::cout << weight << " " << head_type << " jig with " << trailer_type << " trailer" << std::endl; }
void Spinner::getLure() { std::cout << weight << " spinner with " << blade_pattern << " " << blade_type << " blade" << std::endl; }
void FactoryPlug::getLure() { std::cout << length << " " << color_pattern << " " << plug_type << std::endl; }
void FactoryFly::getLure() { std::cout << length << " " << color_pattern << " " << tied_pattern << std::endl; }
void SoftPlastic::getLure() { std::cout << length << " " << color_pattern << " " << style << std::endl; }

// Define base class factory method to produce various derived class product instances
std::unique_ptr<Lure> Lure::setLure(lureTypes type, const std::string& char1, const std::string& char2, const std::string& char3) {
    if (type == JIG) { return std::unique_ptr<Lure> ( new FactoryJig(char1, char2, char3) ); }
    else if (type == SPINNER) { return std::unique_ptr<Lure>( new Spinner(char1, char2, char3) ); }
    else if (type == PLUG)  { return std::unique_ptr<Lure>( new FactoryPlug(char1, char2, char3) ); }
    else if (type == FLY)  { return std::unique_ptr<Lure>( new FactoryFly(char1, char2, char3) ); }
    else if (type == SOFTPLASTIC)  { return std::unique_ptr<Lure>( new SoftPlastic(char1, char2, char3) ); }
    else { 
        std::cout << "Warning: lure type is not supported, default to SoftPlastic" << std::endl; 
        return std::unique_ptr<Lure>( new SoftPlastic(char1, char2, char3) );
    }
}

int main(int argc, char *argv[]) {

    std::cout << "Factory design pattern test:" << std::endl;

    // Add several lures to tacklebox to test Factory class implementation
    std::vector< std::unique_ptr<Lure> > tackleBox;
    tackleBox.push_back(Lure::setLure(JIG, "3/8th oz.","football head","Rage Craw"));
    tackleBox.push_back(Lure::setLure(SPINNER,"1/4 oz.","willow leaf","gold"));
    tackleBox.push_back(Lure::setLure(PLUG,"6 inch","Rapala","Fire Tiger"));
    tackleBox.push_back(Lure::setLure(FLY,"3 inch","streamer","blue over white"));
    tackleBox.push_back(Lure::setLure(SOFTPLASTIC,"6 inch","stick bait","watermelon flake"));

    for (int i = 0; i < tackleBox.size(); ++i){
        tackleBox.at(i)->getLure();
    }

    return 0;

}
