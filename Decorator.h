# include <string>
# include <iostream>

class WeaponSystem {
    public:
        virtual ~WeaponSystem() { }
        virtual void getWeaponSystem() = 0;
};

class AssaultRifle : public WeaponSystem {
    public:
        AssaultRifle (std::string in_platform);
        ~AssaultRifle () { }
        void getWeaponSystem();
    private:
        std::string m_platform;
};

// Decorator class
class WeaponAccessories : public WeaponSystem {
    public:
        WeaponAccessories(WeaponSystem *in_platform);
        ~WeaponAccessories();
        void getWeaponSystem();
    private:
        WeaponSystem *m_platform;
};

class Scope : public WeaponAccessories {
    public:
        Scope(WeaponSystem *in_platform, std::string in_scope) : WeaponAccessories(in_platform) { 
            m_scope = in_scope;
        }
        void getWeaponSystem();
    private:
        std::string m_scope;
};

class Foregrip : public WeaponAccessories {
    public:
        Foregrip(WeaponSystem *in_platform, std::string in_foregrip) : WeaponAccessories(in_platform) {
            m_foregrip = in_foregrip;
        }
        void getWeaponSystem();
    private:
        std::string m_foregrip;
};

class Suppressor : public WeaponAccessories {
    public:
        Suppressor(WeaponSystem *in_platform, std::string in_suppressor) : WeaponAccessories(in_platform) {
            m_suppressor = in_suppressor;
        }
        void getWeaponSystem();
    private:
        std::string m_suppressor;
};
