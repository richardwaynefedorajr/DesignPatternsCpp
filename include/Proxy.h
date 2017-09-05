// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description
# include <string>
# include <iostream>
# include <memory>

// Declare subject to be handled by proxy 
class ProxySubject {
    public:
        ProxySubject();
        void setState(int state);
        int getState();
    private:
        int m_state;
};

// Declare proxy to handle subject
class Proxy {
    public:
        Proxy();
        int getProxySubjectState();
        void setProxySubjectState(int state);
    private:
        std::unique_ptr<ProxySubject> m_subject; 
};
