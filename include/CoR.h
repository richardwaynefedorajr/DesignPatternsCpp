// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the chain of responsibility design pattern, in which a base class manages a pointer to the next object instance in the chain of responsibiity for processing fast food orders

# include <string>
# include <iostream>

// Declare enum describing responsibilities
enum FastFood { burger, fries, drink, change };

// Declare base class (pure virtual method overridden for derived class responsibility)
class BaseWorker {
    BaseWorker *m_next_worker;
    public:
        BaseWorker();
        void setNext(BaseWorker *in_worker);
        void addWorker(BaseWorker *in_worker);
        virtual void service(FastFood in_request);
};

// Declare derived classes (override service method based on derived class responsibility)
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
