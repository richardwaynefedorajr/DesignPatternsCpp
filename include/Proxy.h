# include <string>
# include <iostream>
# include <memory>

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
        std::unique_ptr<ProxySubject> m_subject; 
};
