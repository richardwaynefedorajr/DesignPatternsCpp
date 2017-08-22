# include <string>
# include <iostream>

class ProxySubject {
    public:
        ProxySubject();
        void setState(int state);
        int getState();
    private:
        int m_state;
};

class Proxy {
    public:
        Proxy();
        int getProxySubjectState();
        void setProxySubjectState(int state);
    private:
        ProxySubject *m_subject; 
};
