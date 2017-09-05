// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description:
# include "Observer.h"

// Define observer constructor: initialize subject and state to be observed
Observer::Observer(SubjectClass *subject, MonitorState state) {
    m_state = state;
    subject->activateObserver(this, state);
}

// Define observer method to get state being observed
template <class T>
void Observer::reportState(T state, std::string name) { std::cout << name << " state: " << state << std::endl; }

// Define constructor for object to be observed: initialize states and observers
SubjectClass::SubjectClass(std::string string1, std::string string2, double double1, double double2, int int1, int int2) :
 m_string1(string1), m_string2(string2), m_double1(double1), m_double2(double2), m_int1(int1), m_int2(int2) {
   
    m_string1_obs = NULL;
    m_string2_obs = NULL;
    m_double1_obs = NULL;
    m_double2_obs = NULL;
    m_int1_obs = NULL;
    m_int2_obs = NULL;

};

// Define method to set observer based on state to be observed: called by observer passing pointer to self as argument
void SubjectClass::activateObserver(Observer *observer, MonitorState state) {
    switch ( state ) {
        case STRING1:
            m_string1_obs = observer;
            break;
        case STRING2:
            m_string2_obs = observer;
            break;
        case DOUBLE1:
            m_double1_obs = observer;
            break;
        case DOUBLE2:
            m_double2_obs = observer;
            break;
        case INT1:
            m_int1_obs = observer;
            break;
        case INT2:
            m_int2_obs = observer;
            break;
    }
}

// Define method to call observer methods to get each observed state
void SubjectClass::publishState() {
    if ( m_string1_obs ) { m_string1_obs->reportState(m_string1, "String1"); }
    if ( m_string2_obs ) { m_string2_obs->reportState(m_string2, "String2"); }
    if ( m_double1_obs ) { m_double1_obs->reportState(m_double1, "Double1"); }
    if ( m_double2_obs ) { m_double2_obs->reportState(m_double2, "Double2"); }
    if ( m_int1_obs ) { m_int1_obs->reportState(m_int1, "Int1"); }
    if ( m_int2_obs ) { m_int2_obs->reportState(m_int2, "Int2"); }
}
