// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the command design pattern, in which the functionality for football players running drills and the coach's call to make them run is encapsulated in a TeamMember class, and a Command class is used to encapsulte the request itself 

# include "Command.h"

// Define command class constructor (accept pointers to actor and action to execute as arguments)
Command::Command(TeamMember *teammember, void(TeamMember::*action)()) : m_teammember(teammember), m_action(action) { }

// Define execution class constructor (accept command instance as argument) 
TeamMember::TeamMember(std::string name, std::unique_ptr<Command> command) : m_name(name), m_command(std::move(command)) { } 

// Define command method to call action method
void Command::execute() { (m_teammember->*m_action)(); }

// Define execution class functionality to call command functionality
void TeamMember::commandDrills() { 
    std::cout << m_name << " makes ";
    m_command->execute(); 
}

// Define execution class functionality (executed when called by command class instance)
void TeamMember::runLaps() { std::cout << m_name << " run laps" << std::endl; } 
void TeamMember::runDBDrills() { std::cout << m_name << " run DB drills" << std::endl; } 
void TeamMember::runLinemanDrills() { std::cout << m_name << " run lineman drills" << std::endl; } 




