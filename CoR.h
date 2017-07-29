# include <string>
# include <iostream>

enum FastFood { burger, fries, drink, change };

class BaseWorker {
    BaseWorker *m_next_worker;
    public:
        BaseWorker();
        void setNext(BaseWorker *in_worker);
        void addWorker(BaseWorker *in_worker);
        virtual void service(FastFood in_request);
};

class Cashier : public BaseWorker {
    public:
        void service(FastFood in_request);
};

class Cook : public BaseWorker {
    public:
        void service(FastFood in_request);
};

class Runner : public BaseWorker {
    public:
        void service(FastFood in_request);
};
