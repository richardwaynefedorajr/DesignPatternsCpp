# Implementation Specifics
File level synopsis of "Gang of Four" design pattern implementations in C++

## Factory.h/cpp
Implementation of the factory design pattern, in which factory method setLure of base class Lure creates instances of child class objects (representing different types of fishing lures in a tacklebox)

## Adapter.h/cpp
Implementation of the adapter design pattern, in which a client using weight in pounds may interact through the adapter with an interface expecting mass in kilograms

## Builder.h/cpp
Implementation of the builder design pattern, in which a truck's characteristics are defined by the member functions of a builder object, which is used by the dealership object to create and supply the truck to the client

## AbstractFactory.h/cpp
Implementation of the abstract factory design pattern, in which a bank base class is overloaded for various branch names and produces a set of accounts

## Singleton.h/cpp
Implementation of the singleton design pattern, in which a single instance of class SingletonClass is ensured and provides "read/write" access to member string

## Facade.h/cpp
Implementation of the facade design pattern, in which an instance of the FacadeClass provides a single interface to subsystems which provide the current date and time

## Mediator.h/cpp
Implementation of the mediator design pattern, in which the interaction between "stooge" objects, representing the classic slapstick comics The Three Stooges, is encapsulated in a mediator class

## Decorator.h/cpp
Implementation of the decorator design pattern, in which assault rifle accessories are added to a base class dynamically

## Bridge.h/cpp
Implementation of the bridge design pattern, in which the interface and implementation specifics for creating fishing lures are abstracted behind LureType and LureCharacteristic base classes

## CoR.h/cpp
Implementation of the chain of responsibility design pattern, in which a base class manages a pointer to the next object instance in the chain of responsibiity for processing fast food orders

## Command.h/cpp
Implementation of the command design pattern, in which the functionality for football players running drills and the coach's call to make them run is encapsulated in a TeamMember class, and a Command class is used to encapsulte the request itself 

## Flyweight.h/cpp
Implementation of the flyweight design pattern, in which a factory is used to create and store instances of a rectangle class, with intrinsic dimensions and an extrinsic location to be drawn in the terminal

## Interpreter.h/cpp
Implementation of the interpreter design pattern, in which the rules to translate an integer into text are distributed accross derived interpreter subclasses

## Observer.h/cpp
Implementation of the observer design pattern, in which a subject class uses an object class interface to provide updates on the state of its members

## Prototype.h/cpp
Implementation of the prototype design pattern, in which a factory class maintains a set of prototype instances of a derived class which clone themselves to produce additional instances

## Proxy.h/cpp
Implementation of the proxy design pattern, in which a proxy provides the client "read/write" access to a subject

## State.h/cpp
Implementation of the state design pattern, in which states are represented in derived classes owned by a member pointer of the subject class

## Strategy.h/cpp
Implementation of the strategy design pattern, in which the algorithms for generating common mathematical sequences are encapsulated in derived classes and passed to a client interface class

## Visitor.h/cpp
Implementation of the visitor design pattern, in which a visitor lure class "visits" a fish class and either catches or does not catch them depending on the derived class of each

## Memento.h/cpp
Implementation of the memento design pattern, in which a Memento class encapsulates a "snapshot" of on object's state and provides access to previous states 
