# include "Memento.h"

Memento::Memento(std::string StringState) { m_state = StringState; } 

InputString::InputString(std::string init_string) { m_string = init_string; }

InputReceiver::InputReceiver(InputString *receiver, Action action) {
    m_receiver = receiver;
    m_action = action;
    m_num_inputs = 0;
    m_limit = 0;
}

void InputString::setInput(std::string concat_string) { m_concat_string = concat_string; }

void InputString::concatString() { m_string += m_concat_string; }

std::string InputString::getString() { return m_string; }
        
Memento *InputString::setMemento() { return new Memento(m_string); }

void InputString::resetState(Memento *m) { m_string = m->m_state; }

void InputReceiver::execute() {
    m_memento_list.push_back(m_receiver->setMemento());
    m_input_list.push_back(this);
    if (m_num_inputs > m_limit) { m_limit = m_num_inputs; }
    m_num_inputs++;
    (m_receiver->*m_action)();
}

void InputReceiver::undo() {
    if (m_num_inputs == 0) { std::cout << "Overrun input directives!" << std::endl; return; }
    m_input_list.at(m_num_inputs - 1)->m_receiver->resetState(m_memento_list.at(m_num_inputs - 1));
    m_num_inputs--;
}

void InputReceiver::redo() {
    if (m_num_inputs > m_limit) { std::cout << "Overrun input directives!" << std::endl; return; }
    (m_input_list.at(m_num_inputs)->m_receiver->*(m_input_list.at(m_num_inputs)->m_action))();
    m_num_inputs++;
}
