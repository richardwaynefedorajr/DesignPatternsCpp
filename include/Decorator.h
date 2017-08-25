# include <string>
# include <iostream>
# include <memory>

// Declare "super" base class parent to base class to be decorated and decorator base class
class WeaponSystem {
    public:
        virtual void getWeaponSystem() = 0;
};

// Declare base class to be decorated (inherit from "super" base class)
class AssaultRifle : public WeaponSystem {
    public:
        AssaultRifle (std::string in_platform);
        void getWeaponSystem();
    private:
        std::string m_platform;
};

// Declare decorator base class (inherit from "super" base class)
class WeaponAccessories : public WeaponSystem {
    public:
        WeaponAccessories(std::shared_ptr<WeaponSystem> in_platform);
        void getWeaponSystem();
    private:
        std::shared_ptr<WeaponSystem> m_platform;
};

// Declare derived decorator classes
class Scope : public WeaponAccessories {
    public:
        Scope(std::shared_ptr<WeaponSystem> in_platform, std::string in_scope) : WeaponAccessories(in_platform) { 
            m_scope = in_scope;
        }
        void getWeaponSystem();
    private:
        std::string m_scope;
};

class Foregrip : public WeaponAccessories {
    public:
        Foregrip(std::shared_ptr<WeaponSystem> in_platform, std::string in_foregrip) : WeaponAccessories(in_platform) {
            m_foregrip = in_foregrip;
        }
        void getWeaponSystem();
    private:
        std::string m_foregrip;
};

class Suppressor : public WeaponAccessories {
    public:
        Suppressor(std::shared_ptr<WeaponSystem> in_platform, std::string in_suppressor) : WeaponAccessories(in_platform) {
            m_suppressor = in_suppressor;
        }
        void getWeaponSystem();
    private:
        std::string m_suppressor;
};
