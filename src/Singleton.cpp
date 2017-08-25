# include "Singleton.h"

// Define singleton instance
SingletonClass* SingletonClass::m_instance = NULL;

// Lazy initialization
SingletonClass* SingletonClass::getInstance() {
    if (!m_instance) { m_instance = new SingletonClass(); }
    return m_instance;
}

// Define member access methods
void SingletonClass::setString(std::string in_string) { m_string = in_string; }
std::string SingletonClass::getString() { return m_string; }
