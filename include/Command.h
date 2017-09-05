// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description
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
