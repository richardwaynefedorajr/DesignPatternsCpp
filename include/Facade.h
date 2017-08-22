# include <iostream>
# include <string>
# include <ctime>

// Declaration of date subsystem class
class DateClass {
    public:
        void getDate();
    private:
        time_t m_time;
        struct tm * m_time_now;
};

// Declaration of time subsystem class
class TimeClass {
    public:
        void getTime();
    private:
        time_t m_time;
        struct tm * m_time_now;
};

// Declaration of facade class to interface with time and date functionality
class FacadeClass {
    public:
        void getDateAndTime();
    private:
        DateClass m_DC;
        TimeClass m_TC;
};
