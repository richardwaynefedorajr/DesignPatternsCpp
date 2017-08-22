# include "Interpreter.h"

Interpreter::Interpreter() {
    m_input = 0;
    m_hundred = new Hundred(NULL);
    m_ten = new Ten(NULL);
    m_one = new One(NULL);
}

void Interpreter::setInput(int input) { m_input = input; }

void Interpreter::interpret() {
    if ( m_input < 1000 && m_input > 0 ) { 
        m_value = m_one->interpret(m_ten->interpret(m_hundred->interpret(m_input)));
   
        if ( m_ten->m_tens == "teen" ) {
            switch ( m_value ) {
                case 0:
                    m_ten->m_tens = "ten";
                    m_one->m_ones = "";
                    break;
                case 1:
                    m_ten->m_tens = "eleven";
                    m_one->m_ones = "";
                    break;
                case 2:
                    m_ten->m_tens = "twelve";
                    break;
                case 3:
                    m_ten->m_tens = "thirteen";
                    m_one->m_ones = "";
                    break;
                case 4:
                    m_ten->m_tens = "fourteen";
                    m_one->m_ones = "";
                    break;
                case 5:
                    m_ten->m_tens = "fifteen";
                    m_one->m_ones = "";
                    break;
                case 6:
                    m_ten->m_tens = "sixteen";
                    m_one->m_ones = "";
                    break;
                case 7:
                    m_ten->m_tens = "seventeen";
                    m_one->m_ones = "";
                    break;
                case 8:
                    m_ten->m_tens = "eighteen";
                    m_one->m_ones = "";
                    break;
                case 9:
                    m_ten->m_tens = "nineteen";
                    m_one->m_ones = "";
                    break;
            }
        
            std::cout << m_input << ": " << m_hundred->m_hundreds << " " << m_ten->m_tens << " " << m_one->m_ones << std::endl;
        }
    }
    
    else { std::cout << "Please set input between 0 and 1000!" << std::endl; }

}

int Hundred::interpret(int number) { 

    switch ( number / 100 ) {
        case 0:
            m_hundreds = "";
            break;
        case 1:
            m_hundreds = "one hundred and";
            break;
        case 2:
            m_hundreds = "two hundred and";
            break;
        case 3:
            m_hundreds = "three hundred and";
            break;
        case 4:
            m_hundreds = "four hundred and";
            break;
        case 5:
            m_hundreds = "five hundred and";
            break;
        case 6:
            m_hundreds = "six hundred and";
            break;
        case 7:
            m_hundreds = "seven hundred and";
            break;
        case 8:
            m_hundreds = "eight hundred and";
            break;
        case 9:
            m_hundreds = "nine hundred and";
            break;
    }
    
    return number % 100; 

}

int Ten::interpret(int number) { 
    
    switch ( number / 10 ) {
        case 0:
            m_tens = "";
            break;
        case 1:
            m_tens = "teen";
            break;
        case 2:
            m_tens = "twenty";
            break;
        case 3:
            m_tens = "thirty";
            break;
        case 4:
            m_tens = "forty";
            break;
        case 5:
            m_tens = "fifty";
            break;
        case 6:
            m_tens = "sixty";
            break;
        case 7:
            m_tens = "seventy";
            break;
        case 8:
            m_tens = "eighty";
            break;
        case 9:
            m_tens = "ninety";
            break;
    }
    
    return number % 10; 

}

int One::interpret(int number) { 

    switch ( number ) {
        case 0:
            m_ones = "";
            break;
        case 1:
            m_ones = "one";
            break;
        case 2:
            m_ones = "two";
            break;
        case 3:
            m_ones = "three";
            break;
        case 4:
            m_ones = "four";
            break;
        case 5:
            m_ones = "five";
            break;
        case 6:
            m_ones = "six";
            break;
        case 7:
            m_ones = "seven";
            break;
        case 8:
            m_ones = "eight";
            break;
        case 9:
            m_ones = "nine";
            break;
    }

    return number; 
}
