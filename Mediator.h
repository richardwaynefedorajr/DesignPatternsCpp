# include <string>
# include <iostream>
# include <memory>

class InteractionMediator;

// Declarations of stooge objects with various interactions
class Larry {
    public:
        Larry(std::shared_ptr<InteractionMediator> mediator);
        void accidentallyHitMoe();
        void getState();
        std::string getName();
        void setState(bool state);
    private:
        bool head_slapped;
        std::string name;
        std::shared_ptr<InteractionMediator> m_mediator;
};

class Curly {
    public:
        Curly(std::shared_ptr<InteractionMediator> mediator);       
        void accidentallyHitMoe();
        void getState();
        std::string getName();
        void setState(bool state);
    private:
        bool eyes_water;
        std::string name;
        std::shared_ptr<InteractionMediator> m_mediator;
};

class Moe {
    public:
        Moe(std::shared_ptr<InteractionMediator> mediator);      
        void slapLarrysHead();
        void pokeCurlysEyes();
        void getState();
        std::string getName();
        void setState(bool state);
    private:
        bool accidentally_hit;
        std::string name;
        std::shared_ptr<InteractionMediator> m_mediator;
};

// Declaration of mediator to encapsulate interactions between stooge objects
class InteractionMediator {
    public:
        InteractionMediator() { }
        void setStooges(std::shared_ptr<Larry> larry, std::shared_ptr<Curly> curly, std::shared_ptr<Moe> moe);
        void LarryHitsMoe(Larry* larry);
        void CurlyHitsMoe(Curly* curly);
        void MoePokesCurly(Moe* moe);
        void MoeSlapsLarry(Moe* moe); 
    private:
        std::shared_ptr<Larry> m_larry;
        std::shared_ptr<Curly> m_curly;
        std::shared_ptr<Moe> m_moe;
};
