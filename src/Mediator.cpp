# include "Mediator.h"

// Constructors for stooge objects: states and mediator initialized
Larry::Larry(std::shared_ptr<InteractionMediator> mediator) { name = "Larry"; m_mediator = mediator; head_slapped = false; } 
Curly::Curly(std::shared_ptr<InteractionMediator> mediator) { name = "Curly"; m_mediator = mediator; eyes_water = false; } 
Moe::Moe(std::shared_ptr<InteractionMediator> mediator) { name = "Moe"; m_mediator = mediator; accidentally_hit = false; } 

// Stooge interaction definitions and set/get utilities
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

// Definition of functionality to set managed stooges
void InteractionMediator::setStooges(std::shared_ptr<Larry> larry, std::shared_ptr<Curly> curly, std::shared_ptr<Moe> moe) {
    m_larry = larry;
    m_curly = curly;
    m_moe = moe;
}

// Definitions of mediator interactions
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
