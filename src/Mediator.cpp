// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the mediator design pattern, in which the interaction between "stooge" objects, representing the classic slapstick comics The Three Stooges, is encapsulated in a mediator class

# include "Mediator.h"

// Define constructors for stooge objects: states and mediator initialized
Larry::Larry(std::shared_ptr<InteractionMediator> mediator) { name = "Larry"; m_mediator = mediator; head_slapped = false; } 
Curly::Curly(std::shared_ptr<InteractionMediator> mediator) { name = "Curly"; m_mediator = mediator; eyes_water = false; } 
Moe::Moe(std::shared_ptr<InteractionMediator> mediator) { name = "Moe"; m_mediator = mediator; accidentally_hit = false; } 

// Define stooge interaction and set/get utilities
void Larry::accidentallyHitMoe() { m_mediator->LarryHitsMoe(this); }
void Larry::getState() {
    if (head_slapped) { std::cout << name << "'s head slapped" << std::endl; }
    else { std::cout << name << "'s head not slapped" << std::endl; }
}
std::string Larry::getName() { return name; }
void Larry::setState(bool state) { head_slapped = state; }

void Curly::accidentallyHitMoe() { m_mediator->CurlyHitsMoe(this); }
void Curly::getState() {
    if (eyes_water) { std::cout << name << "'s eyes water" << std::endl; }
    else { std::cout << name << "'s eyes don't water" << std::endl; }
}
std::string Curly::getName() { return name; }
void Curly::setState(bool state) { eyes_water = state; }

void Moe::slapLarrysHead() { m_mediator->MoeSlapsLarry(this); }
void Moe::pokeCurlysEyes() { m_mediator->MoePokesCurly(this); }
void Moe::getState() {
    if (accidentally_hit) { std::cout << "Moe got hit" << std::endl; }
    else { std::cout << "Moe wasn't hit" << std::endl; }
} 
std::string Moe::getName() { return name; }
void Moe::setState(bool state) { accidentally_hit = state; }

// Define functionality to set managed stooges
void InteractionMediator::setStooges(std::shared_ptr<Larry> larry, std::shared_ptr<Curly> curly, std::shared_ptr<Moe> moe) {
    m_larry = larry;
    m_curly = curly;
    m_moe = moe;
}

// Define mediator interactions
void InteractionMediator::LarryHitsMoe(Larry* larry) { 
    std::cout << "Instigator: " << larry->getName() << std::endl;
    m_moe->setState(true);
    m_moe->getState(); 
}

void InteractionMediator::CurlyHitsMoe(Curly* curly) { 
    std::cout << "Instigator: " << curly->getName() << std::endl;
    m_moe->setState(true); 
    m_moe->getState(); 
}

void InteractionMediator::MoePokesCurly(Moe* moe) { 
    std::cout << "Instigator: " << moe->getName() << std::endl;
    m_curly->setState(true); 
    m_curly->getState(); 
}

void InteractionMediator::MoeSlapsLarry(Moe* moe) { 
    std::cout << "Instigator: " << moe->getName() << std::endl;
    m_larry->setState(true); 
    m_larry->getState(); 
}

int main(int argc, char *argv[]) {

    std::cout << "Mediator design pattern test:" << std::endl;

    std::shared_ptr<InteractionMediator> im( new InteractionMediator() );

    std::shared_ptr<Larry> larry( new Larry(im) ); 
    std::shared_ptr<Curly> curly( new Curly(im) );
    std::shared_ptr<Moe> moe( new Moe(im) );
    
    im->setStooges(larry, curly, moe);

    larry->accidentallyHitMoe();
    curly->accidentallyHitMoe();
    moe->pokeCurlysEyes();
    moe->slapLarrysHead();

    return 0;

}
