# include <iostream>
# include <string>
# include <ctime>

class DateClass {
    public:
        void getDate();
    private:
        time_t m_time;
        struct tm * m_time_now;
};

class TimeClass {
    public:
        void getTime();
    private:
        time_t m_time;
        struct tm * m_time_now;
};

class FacadeClass {
    public:
        void getDateAndTime();
    private:
        DateClass m_DC;
        TimeClass m_TC;
};
