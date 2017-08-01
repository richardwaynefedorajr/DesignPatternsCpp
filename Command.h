# include <string>
# include <iostream>

class TeamMember;

class Command {
    public:
        TeamMember *m_teammember;
        void(TeamMember::*m_action)();
        Command(TeamMember *teammember = 0, void(TeamMember::*in_action)() = 0);
        void execute();
};

class TeamMember {
    public:
        std::string m_name;
        Command m_command;
        TeamMember(std::string name, Command command);
        void commandDrills();
        void runLaps(); 
        void runDBDrills();
        void runLinemanDrills();
};
