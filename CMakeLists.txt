cmake_minimum_required(VERSION 3.2)
project(DesignPatternsCpp)
set(CMAKE_CXX_STANDARD 11)

#Bring the headers into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/main.cpp src/file.cpp)

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "src/*.cpp")

add_executable(factory "src/Factory.cpp")
add_executable(adapter "src/Adapter.cpp")
add_executable(builder "src/Builder.cpp")
add_executable(abstractFactory "src/AbstractFactory.cpp")
add_executable(memento "src/Memento.cpp")
add_executable(singleton "src/Singleton.cpp")
add_executable(facade "src/Facade.cpp")
add_executable(mediator "src/Mediator.cpp")
add_executable(decorator "src/Decorator.cpp")
add_executable(bridge "src/Bridge.cpp")
add_executable(cor "src/CoR.cpp")
add_executable(command "src/Command.cpp")
add_executable(composite "src/Composite.cpp")
add_executable(flyweight "src/Flyweight.cpp")
add_executable(interpreter "src/Interpreter.cpp")
add_executable(observer "src/Observer.cpp")
add_executable(prototype "src/Prototype.cpp")
add_executable(proxy "src/Proxy.cpp")
add_executable(state "src/State.cpp")
add_executable(strategy "src/Strategy.cpp")
add_executable(visitor "src/Visitor.cpp")
add_executable(pointerVariations "src/PointerVariations.cpp")
add_executable(functionPointers "src/FunctionPointers.cpp")
