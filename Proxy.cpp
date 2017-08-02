# include "Proxy.h"

Subject::Subject() : m_state(0) { }
void Subject::setState(int state) { m_state = state; }
int Subject::getState() { return m_state; }

Proxy::Proxy() { m_subject = NULL; }
int Proxy::getSubjectState() { 
    if ( !m_subject ) { m_subject = new Subject(); }
    return m_subject->getState();
}
void Proxy::setSubjectState(int state) { m_subject->setState(state); }
