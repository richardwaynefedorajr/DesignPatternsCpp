// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the facade design pattern, in which an instance of the FacadeClass provides a single interface to subsystems which provide the current date and time

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

int main(int argc, char *argv[]) {

    std::cout << "Facade design pattern test:" << std::endl;

    FacadeClass DateAndTimeInterface;
    DateAndTimeInterface.getDateAndTime();

    return 0;

}
