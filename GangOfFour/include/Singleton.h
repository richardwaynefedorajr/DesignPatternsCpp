// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declaration for implementation of the singleton design pattern, in which a single instance of class SingletonClass is ensured and provides "read/write" access to member string

# include <string>
# include <iostream>

// Declare singleton class
class SingletonClass {
    public:
        std::string m_string;
        static SingletonClass* getInstance();
        void setString(std::string in_string);
        std::string getString();
    private:
        SingletonClass(std::string s = "Init string") { m_string = s; }
        static SingletonClass* m_instance;
};
