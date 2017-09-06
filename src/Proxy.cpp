// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the proxy design pattern, in which a proxy provides the client "read/write" access to a subject

# include "Proxy.h"

// Define subject funtionality
ProxySubject::ProxySubject() : m_state(0) { }
void ProxySubject::setState(int state) { m_state = state; }
int ProxySubject::getState() { return m_state; }

// Define proxy: lazy initialization
Proxy::Proxy() { m_subject = NULL; }
int Proxy::getProxySubjectState() { 
    if ( !m_subject ) { m_subject = std::unique_ptr<ProxySubject>( new ProxySubject() ); }
    return m_subject->getState();
}
void Proxy::setProxySubjectState(int state) { m_subject->setState(state); }
