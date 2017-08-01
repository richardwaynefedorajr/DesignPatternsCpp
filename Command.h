# include <string>
# include <iostream>

class TeamMember;

class Command {
    TeamMember *m_teammember;
    void(TeamMember::*method)();
    public:
        Command(TeamMember *in_teammember = 0, void(TeamMember::*in_method)() = 0);
        void execute();
};

class TeamMember {
    public:
        std::string m_name;
        virtual void command() = 0;
        virtual void action() = 0;
};

class Coach : public TeamMember {
    public:
        void command();
};

class DefensiveBack : public TeamMember {
    public:
        void action();
};

class RunningBack : public TeamMember {
    public:
        void action();
};

class Lineman : public TeamMember {
    public:
        void action();
};
