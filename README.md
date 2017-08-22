### DesignPatternsCpp
A set of implementations of common C++ design patterns proposed by the "Gang of Four" in Design Patterns: Elements of Reusable Object-Oriented Software [Vlissides, John, et al. "Design patterns: Elements of reusable object-oriented software." Reading: Addison-Wesley 49.120 (1995): 11.]

main.cpp contains the main test interface, with separation comments for each design pattern... uncomment the desired design pattern block to test

# Maintainer:
Rich Fedora
richardwaynefedorajr@gmail.com

# Factory.h/cpp
Implementation of the factory design pattern, in which factory method setLure of base class Lure creates instances of child class objects (representing different types of fishing lures in a tacklebox)

# Adapter.h/cpp
Implementation of the adapter design pattern, in which a client using weight in pounds may interact through the adapter with an interface expecting mass in kilograms

# Builder.h/cpp
Implementation of the builder design pattern, in which a truck's characteristics are defined by the member functions of a builder object, which is used by the dealership object to create and supply the truck to the client

# AbstractFactory.h/cpp
Implementation of the abstract factory design pattern, in which a bank base class is overloaded for various branch names and produces a set of accounts

# Singleton.h/cpp
Implementation of the singleton design pattern, in which a single instance of class SingletonClass is ensured and provides "read/write" access to member string

# Facade.h/cpp
Implementation of the facade design pattern, in which an instance of the FacadeClass provides a single interface to subsystems which provide the current date and time

# Mediator.h/cpp
Implementation of the mediator design pattern, in which the interaction between "stooge" objects, representing the classic slapstick comics The Three Stooges, is encapsulated in a mediator class

# Decorator.h/cpp
Implementation of the decorator design pattern, in which assault rifle accessories are added to a base class dynamically

# Bridge.h/cpp
Implementation of the bridge design pattern, in which the interface and implementation specifics for creating fishing lures are abstracted behind LureType and LureCharacteristic base classes

# CoR.h/cpp
Implementation of the chain of responsibility design pattern, in which a base class manages a pointer to the next object instance in the chain of responsibiity for processing fast food orders

# Command.h/cpp
Implementation of the command design pattern, in which the functionality for football players running drills and the coach's call to make them run is encapsulated in a TeamMember class, and a Command class is used to encapsulte the request itself 

# Flyweight.h/cpp
Implementation of the flyweight design pattern, in which a factory is used to create and store instances of a rectangle class, with intrinsic dimensions and an extrinsic location to be drawn in the terminal

# Interpreter.h/cpp
Implementation of the interpreter design pattern, in which the rules to translate an integer into text are distributed accross derived interpreter subclasses

# Observer.h/cpp
Implementation of the observer design pattern, in which a subject class uses an object class interface to provide updates on the state of its members

# Prototype.h/cpp
Implementation of the prototype design pattern, in which a factory class maintains a set of prototype instances of a derived class which clone themselves to produce additional instances

# Proxy.h/cpp
Implementation of the proxy design pattern, in which a proxy provides the client "read/write" access to a subject

# State.h/cpp
Implementation of the state design pattern, in which states are represented in derived classes owned by a member pointer of the subject class

# Strategy.h/cpp
Implementation of the strategy design pattern, in which the algorithms for generating common mathematical sequences are encapsulated in derived classes and passed to a client interface class

# Visitor.h/cpp
Implementation of the visitor design pattern, in which a visitor lure class "visits" a fish class and either catches or does not catch them depending on the derived class of each

# Memento.h/cpp
Implementation of the memento design pattern, in which a Memento class encapsulates a "snapshot" of on object's state and provides access to previous states 

# Issues

FINISHED MEMORY MANAGMENT AND RECOMMENTING UPDATES UP TO HERE

Update with Rule of 5 and test it

Figure out if there is a better way to manage singleton memory, and if destructor needs to explicitly delete instance

Anything else we can do with Facade?

Update with std::memory_management, recomment

Look at std::function for pointers to methods

Make sure public/private is correct, find places to use static, virtual, etc.

Use templates whenever possible

Try Singleton implementations of Abstract Factory, Builder, Prototype, Facade, and State

Try Chain of Responsibility using Command to represent requests as objects

Try Command using Memento to maintain state required to undo an operation

Try combining Factory, Abstract Factory, and Bridge design classes with Composite to allow for access to various lure attributes in collection

Update Prototype with Singleton to replace static in Source Making example

Update with standard naming conventions:
class ClassName { ... }  - class
functionName(arg1, arg2, arg3) - function (same syntax for function calls)
m_variable - member variablebstract Factory, Builder, Prototype, Facade, and State

variable - input variable
ENUM - enum member
keyword ( arg, arg, arg ) - for, if, while, switch, etc.

State dependencies (state std::libraries, don't need to link)
BOOST, OpenCV type stuff link as well (version info)
Latest continuous integration links
Change documentation to website -> add cloning, compilation info, etc. 
Add architecture/OS environment structure using Travis
Start creating issues out of to-do work
