// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description:
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


