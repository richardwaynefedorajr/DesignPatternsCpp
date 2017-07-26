# include <string>

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
