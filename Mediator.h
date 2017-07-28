# include <string>
# include <iostream>

class InteractionMediator;

class Larry {
    public:
        Larry(InteractionMediator* mediator);
        void accidentallyHitMoe();
        void getState();
        std::string getName();
        void setState(bool state);
    private:
        bool head_slapped;
        std::string name;
        InteractionMediator* m_mediator;
};

class Curly {
    public:
        Curly(InteractionMediator* mediator);       
        void accidentallyHitMoe();
        void getState();
        std::string getName();
        void setState(bool state);
    private:
        bool eyes_water;
        std::string name;
        InteractionMediator* m_mediator;
};

class Moe {
    public:
        Moe(InteractionMediator* mediator);       
        void slapLarrysHead();
        void pokeCurlysEyes();
        void getState();
        std::string getName();
        void setState(bool state);
    private:
        bool accidentally_hit;
        std::string name;
        InteractionMediator* m_mediator;
};

class InteractionMediator {
    public:
        InteractionMediator() { }
        void getStooges(Larry* in_larry, Curly* in_curly, Moe* in_moe);
        void LarryHitsMoe(Larry* in_larry);
        void CurlyHitsMoe(Curly* in_curly);
        void MoePokesCurly(Moe* in_moe);
        void MoeSlapsLarry(Moe* in_moe); 
    private:
        Larry* m_larry;
        Curly* m_curly;
        Moe* m_moe;
};
