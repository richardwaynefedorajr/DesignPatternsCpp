// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the decorator design pattern, in which assault rifle accessories are added to a base class dynamically

# include "Decorator.h"

// Define base class to be decorated, initialize platform name
AssaultRifle::AssaultRifle(std::string in_platform) { m_platform = in_platform; }
void AssaultRifle::getWeaponSystem() { std::cout << "Weapon System: " << m_platform; }

// Define base decorator class, initialized with pointer to class to be decorated
WeaponAccessories::WeaponAccessories(std::shared_ptr<WeaponSystem> in_platform) { m_platform = in_platform; }
void WeaponAccessories::getWeaponSystem() { m_platform->getWeaponSystem(); }
    
void Scope::getWeaponSystem() { WeaponAccessories::getWeaponSystem(); std::cout << "Scope: " << m_scope; }

void Foregrip::getWeaponSystem() { WeaponAccessories::getWeaponSystem(); std::cout << "Foregrip: " << m_foregrip; }

void Suppressor::getWeaponSystem() { WeaponAccessories::getWeaponSystem(); std::cout << "Suppressor: " << m_suppressor; }

int main(int argc, char *argv[]) {
   
    std::cout << "Decorator design pattern test" << std::endl;

    std::shared_ptr<WeaponSystem> base_platform( new AssaultRifle("M4 ") );
    std::shared_ptr<WeaponSystem> with_scope( new Scope( base_platform, "red dot " ) );
    std::shared_ptr<WeaponSystem> with_scope_and_foregrip( new Foregrip( with_scope,"vertical foregrip " ) );
    std::shared_ptr<WeaponSystem> with_scope_and_foregrip_and_suppressor( new Suppressor( with_scope_and_foregrip, "AAC M4-2000 ") );
    
    base_platform->getWeaponSystem();
    std::cout << std::endl; 

    with_scope->getWeaponSystem();
    std::cout << std::endl; 

    with_scope_and_foregrip->getWeaponSystem();
    std::cout << std::endl; 

    with_scope_and_foregrip_and_suppressor->getWeaponSystem();
    std::cout << std::endl; 

    return 0;

}
