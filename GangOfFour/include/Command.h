// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the command design pattern, in which the functionality for football players running drills and the coach's call to make them run is encapsulated in a TeamMember class, and a Command class is used to encapsulte the request itself 

# include <string>
# include <iostream>
# include <memory>

class TeamMember;

// Declare command class
class Command {
    public:
        TeamMember *m_teammember;
        void(TeamMember::*m_action)();
        Command(TeamMember *teammember = 0, void(TeamMember::*action)() = 0);
        void execute();
};

// Declare execution class (execute commands)
class TeamMember {
    public:
        std::string m_name;
        std::unique_ptr<Command> m_command;
        TeamMember(std::string name, std::unique_ptr<Command> command);
        void commandDrills();
        void runLaps(); 
        void runDBDrills();
        void runLinemanDrills();
};
