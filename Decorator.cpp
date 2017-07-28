# include "Decorator.h"

AssaultRifle::AssaultRifle(std::string in_platform) { m_platform = in_platform; }
void AssaultRifle::getWeaponSystem() { std::cout << "Weapon System: " << m_platform; }

WeaponAccessories::WeaponAccessories(WeaponSystem *in_platform) { m_platform = in_platform; }
WeaponAccessories::~WeaponAccessories() { delete m_platform; }
void WeaponAccessories::getWeaponSystem() { m_platform->getWeaponSystem(); }
    
void Scope::getWeaponSystem() { WeaponAccessories::getWeaponSystem(); std::cout << "Scope: " << m_scope; }

void Foregrip::getWeaponSystem() { WeaponAccessories::getWeaponSystem(); std::cout << "Foregrip: " << m_foregrip; }

void Suppressor::getWeaponSystem() { WeaponAccessories::getWeaponSystem(); std::cout << "Suppressor: " << m_suppressor; }


