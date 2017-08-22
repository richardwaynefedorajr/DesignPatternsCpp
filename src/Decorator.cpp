# include "Decorator.h"

// Definition of base class to be decorated, initialize platform name
AssaultRifle::AssaultRifle(std::string in_platform) { m_platform = in_platform; }
void AssaultRifle::getWeaponSystem() { std::cout << "Weapon System: " << m_platform; }

// Definition of base decorator class, initialized with pointer to class to be decorated
WeaponAccessories::WeaponAccessories(std::shared_ptr<WeaponSystem> in_platform) { m_platform = in_platform; }
void WeaponAccessories::getWeaponSystem() { m_platform->getWeaponSystem(); }
    
void Scope::getWeaponSystem() { WeaponAccessories::getWeaponSystem(); std::cout << "Scope: " << m_scope; }

void Foregrip::getWeaponSystem() { WeaponAccessories::getWeaponSystem(); std::cout << "Foregrip: " << m_foregrip; }

void Suppressor::getWeaponSystem() { WeaponAccessories::getWeaponSystem(); std::cout << "Suppressor: " << m_suppressor; }

