// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description
# include <string>
# include <iostream>
# include <vector>

// Declare enum to indicate state to observe
enum MonitorState { STRING1, STRING2, DOUBLE1, DOUBLE2, INT1, INT2 };

class SubjectClass;

// Declare observer class
class Observer {
    public:
        Observer(SubjectClass *subject, MonitorState state);
        template <class T>
        void reportState(T state, std::string name);
        MonitorState m_state;
};

// Declare class to be observed
class SubjectClass {
    public:
        SubjectClass(std::string string1, std::string string2, double double1, double double2, int int1, int int2);
        void activateObserver(Observer *observer, MonitorState state);
        void publishState();
    private:
        Observer *m_string1_obs;
        Observer *m_string2_obs;
        Observer *m_double1_obs;
        Observer *m_double2_obs;
        Observer *m_int1_obs;
        Observer *m_int2_obs;
        
        std::string m_string1;
        std::string m_string2;
        double m_double1;
        double m_double2;
        int m_int1;
        int m_int2;
};
