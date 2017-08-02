# include <string>
# include <iostream>

class Subject {
    public:
        Subject();
        void setState(int state);
        int getState();
    private:
        int m_state;
};

class Proxy {
    public:
        Proxy();
        int getSubjectState();
        void setSubjectState(int state);
    private:
        Subject *m_subject; 
};
