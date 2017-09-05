// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description:
# include "Facade.h"

// Define facade interface: encapsulate subsystem functionality
void FacadeClass::getDateAndTime() { 
    std::cout << "Date:" << std::endl;
    m_DC.getDate();
    std::cout << "Time:" << std::endl;
    m_TC.getTime();
}

// Define date subsystem functionality
void DateClass::getDate() {
    m_time = time(0);
    m_time_now = localtime( & m_time );
    std::cout << (m_time_now->tm_mon + 1) << "/" << m_time_now->tm_mday << "/" << (m_time_now->tm_year + 1900) << std::endl; 
}

// Define time subsystem functionality
void TimeClass::getTime() {
    m_time = time(0);
    m_time_now = localtime( & m_time );
    std::cout << m_time_now->tm_hour << ":" << m_time_now->tm_min << ":" << m_time_now->tm_sec << std::endl; 
}
