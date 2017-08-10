# include "Facade.h"

// Facade interface definition encapsulates date and time functionality
void FacadeClass::getDateAndTime() { 
    std::cout << "Date:" << std::endl;
    m_DC.getDate();
    std::cout << "Time:" << std::endl;
    m_TC.getTime();
}

// Date functionality definition
void DateClass::getDate() {
    m_time = time(0);
    m_time_now = localtime( & m_time );
    std::cout << (m_time_now->tm_mon + 1) << "/" << m_time_now->tm_mday << "/" << (m_time_now->tm_year + 1900) << std::endl; 
}

// Time functionality definition
void TimeClass::getTime() {
    m_time = time(0);
    m_time_now = localtime( & m_time );
    std::cout << m_time_now->tm_hour << ":" << m_time_now->tm_min << ":" << m_time_now->tm_sec << std::endl; 
}
