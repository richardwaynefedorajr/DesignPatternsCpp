// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the builder design pattern, in which a truck's characteristics are defined by the member functions of a builder object, which is used by the dealership object to create and supply the truck to the client

# include <string>
# include <iostream>
# include <memory>

// Declare product class
class Truck {
    public:
        void setMake(const std::string& make);
        void setDoors(const std::string& doors);
        void setEngine(const std::string& engine);
        void setDrive(const std::string& drive);
        void printStats();
    private:
        std::string m_make, m_doors, m_engine, m_drive;
};

// Declare abstract builder class
class TruckBuilder {
    public:
        virtual ~TruckBuilder() { };
        std::unique_ptr<Truck> getTruck();
        void createNewTruck();
        virtual void buildMake() = 0;
        virtual void buildDoors() = 0;
        virtual void buildEngine() = 0;
        virtual void buildDrive() = 0;
    protected:
        std::unique_ptr<Truck> m_truck;
};

// Declare derived builder class
class RamBuilder : public TruckBuilder {
    public:
        virtual ~RamBuilder() { };
        virtual void buildMake();
        virtual void buildDoors();
        virtual void buildEngine();
        virtual void buildDrive();
};

class FordBuilder : public TruckBuilder {
    public:
        virtual ~FordBuilder() { };
        virtual void buildMake();
        virtual void buildDoors();
        virtual void buildEngine();
        virtual void buildDrive();
};

// Declare builder client
// Argument of makeTruck() is derived builder object which encapsulates desired product
class TruckDealership {
    public:
        void lookAtTruck();
        void makeTruck(std::unique_ptr<TruckBuilder> tb);
        private:
            std::unique_ptr<TruckBuilder> m_truckBuilder;
};
