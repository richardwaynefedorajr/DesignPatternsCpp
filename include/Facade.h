// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description
# include <iostream>
# include <string>
# include <ctime>

// Declare date subsystem class
class DateClass {
    public:
        void getDate();
    private:
        time_t m_time;
        struct tm * m_time_now;
};

// Declare time subsystem class
class TimeClass {
    public:
        void getTime();
    private:
        time_t m_time;
        struct tm * m_time_now;
};

// Declare facade class to interface with subsystem functionality
class FacadeClass {
    public:
        void getDateAndTime();
    private:
        DateClass m_DC;
        TimeClass m_TC;
};
