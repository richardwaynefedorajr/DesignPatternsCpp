# include "Command.h"

Command::Command(TeamMember *teammember, void(TeamMember::*action)()) : m_teammember(teammember), m_action(action) { }

TeamMember::TeamMember(std::string name, Command command) : m_name(name), m_command(command) { } 

void Command::execute() { (m_teammember->*m_action)(); }

void TeamMember::commandDrills() { 
    std::cout << m_name << " makes ";
    m_command.execute(); 
}
void TeamMember::runLaps() { std::cout << m_name << " run laps" << std::endl; } 
void TeamMember::runDBDrills() { std::cout << m_name << " run DB drills" << std::endl; } 
void TeamMember::runLinemanDrills() { std::cout << m_name << " run lineman drills" << std::endl; } 




