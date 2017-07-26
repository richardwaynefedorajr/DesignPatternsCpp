# include <string>
# include <iostream>
# include <vector>

class InputString;

class Memento {
    public:
        Memento(std::string StringState);
    private:
        friend class InputString;
        std::string m_state;
};

class InputString {
    public:
        InputString(std::string init_string);
        void concatString();
        void setInput(std::string concat_string);
        std::string getString();
        Memento *setMemento();
        void resetState(Memento *m);
    private:
        std::string m_string, m_concat_string;
};

class InputReceiver {
    public:
        typedef void(InputString::*Action)();
        InputReceiver(InputString *receiver, Action action);
        virtual void execute();
        void undo();
        void redo();
    protected:
        InputString *m_receiver;
        Action m_action;
        std::vector<InputReceiver*> m_input_list;
        std::vector<Memento*> m_memento_list;
        int m_num_inputs;
        int m_limit;
};
