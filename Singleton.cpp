# include "Singleton.h"

// Definition of singleton instance
SingletonClass* SingletonClass::m_instance = NULL;

// Lazy initialization
SingletonClass* SingletonClass::getInstance() {
    if (!m_instance) { m_instance = new SingletonClass(); }
    return m_instance;
}

// Definition of methods to control access to members
void SingletonClass::setString(std::string in_string) { m_string = in_string; }
std::string SingletonClass::getString() { return m_string; }
