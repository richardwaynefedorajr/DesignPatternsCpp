# include "Factory.h"

// Overridden methods of lure base class
void Jig::getLure() { std::cout << "Weighted hook dressed with skirt, bucktail, or other material" << std::endl; }
void Spinner::getLure() { std::cout << "Spinner blade inline with weight and dressed treble hook" << std::endl; }
void Plug::getLure() { std::cout << "Hard body lure with treble hooks and diving bill" << std::endl; }
void Fly::getLure() { std::cout << "Natrual material tied to hook shank, for use with fly rods" << std::endl; }
void SoftPlastic::getLure() { std::cout << "Soft plastic worm or creature" << std::endl; }

// Lure class factory method to fill tackle box with different lures
Lure *Lure::setLure(lureTypes type) { 
    if (type == JIG) { return new Jig; }
    else if (type == SPINNER) { return new Spinner; }
    else if (type == PLUG)  { return new Plug; }
    else if (type == FLY)  { return new Fly; }
    else if (type == SOFTPLASTIC)  { return new SoftPlastic; }
    else { 
        std::cout << "Warning: lure type is not supported, default to SoftPlastic" << std::endl; 
        return new SoftPlastic;
    }
}

