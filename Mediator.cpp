# include "Mediator.h"

Larry::Larry(InteractionMediator* mediator) { name = "Larry"; m_mediator = mediator; head_slapped = false; } 
Curly::Curly(InteractionMediator* mediator) { name = "Curly"; m_mediator = mediator; eyes_water = false; } 
Moe::Moe(InteractionMediator* mediator) { name = "Moe"; m_mediator = mediator; accidentally_hit = false; } 

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

void InteractionMediator::getStooges(Larry* in_larry, Curly* in_curly, Moe* in_moe) {
    m_larry = in_larry;
    m_curly = in_curly;
    m_moe = in_moe;
}

void InteractionMediator::LarryHitsMoe(Larry* in_larry) { 
    std::cout << "Instigator: " << in_larry->getName() << std::endl;
    m_moe->setState(true);
    m_moe->getState(); 
}

void InteractionMediator::CurlyHitsMoe(Curly* in_curly) { 
    std::cout << "Instigator: " << in_curly->getName() << std::endl;
    m_moe->setState(true); 
    m_moe->getState(); 
}

void InteractionMediator::MoePokesCurly(Moe* in_moe) { 
    std::cout << "Instigator: " << in_moe->getName() << std::endl;
    m_curly->setState(true); 
    m_curly->getState(); 
}

void InteractionMediator::MoeSlapsLarry(Moe* in_moe) { 
    std::cout << "Instigator: " << in_moe->getName() << std::endl;
    m_larry->setState(true); 
    m_larry->getState(); 
}
