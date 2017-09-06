// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the builder design pattern, in which a truck's characteristics are defined by the member functions of a builder object, which is used by the dealership object to create and supply the truck to the client

# include "Builder.h"

// Define product class get/set methods
void Truck::setMake(const std::string& make) { m_make = make; }
void Truck::setDoors(const std::string& doors) { m_doors = doors; }
void Truck::setEngine(const std::string& engine) { m_engine = engine; }
void Truck::setDrive(const std::string& drive) { m_drive = drive; }
void Truck::printStats(){ 
    std::cout << m_drive << " " << m_make << " with " << m_engine << " and " << m_doors << std::endl; 
}

// Define abstract builder class methods
std::unique_ptr<Truck> TruckBuilder::getTruck() { return std::move(m_truck); }
void TruckBuilder::createNewTruck() { m_truck = std::unique_ptr<Truck>(new Truck); }

// Define derived builder class methods
// Derived builder class methods call product class methods
void RamBuilder::buildMake() { m_truck->setMake("RAM"); }
void RamBuilder::buildDoors() { m_truck->setDoors("4 door extended cab"); }
void RamBuilder::buildEngine() { m_truck->setEngine("Cummins straight 6 diesel engine"); }
void RamBuilder::buildDrive() { m_truck->setDrive("4WD"); }

void FordBuilder::buildMake() { m_truck->setMake("Ford F150"); }
void FordBuilder::buildDoors() { m_truck->setDoors("4 door crew cab"); }
void FordBuilder::buildEngine() { m_truck->setEngine("V8 EcoBoost"); }
void FordBuilder::buildDrive() { m_truck->setDrive("4WD"); }

// Define client method
// Argument of makeTruck() is derived builder object which encapsulates desired product characteristics and calls base class methods to build
void TruckDealership::lookAtTruck() { m_truckBuilder->getTruck()->printStats(); }
void TruckDealership::makeTruck(std::unique_ptr<TruckBuilder> tb) {
    m_truckBuilder = std::move(tb);
    m_truckBuilder->createNewTruck();
    m_truckBuilder->buildMake();
    m_truckBuilder->buildDoors();
    m_truckBuilder->buildEngine();
    m_truckBuilder->buildDrive();
}
