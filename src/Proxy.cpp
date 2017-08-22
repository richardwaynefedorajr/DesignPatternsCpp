# include "Proxy.h"

ProxySubject::ProxySubject() : m_state(0) { }
void ProxySubject::setState(int state) { m_state = state; }
int ProxySubject::getState() { return m_state; }

Proxy::Proxy() { m_subject = NULL; }
int Proxy::getProxySubjectState() { 
    if ( !m_subject ) { m_subject = new ProxySubject(); }
    return m_subject->getState();
}
void Proxy::setProxySubjectState(int state) { m_subject->setState(state); }
