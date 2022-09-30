// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the abstract factory design pattern, in which a bank base class is overloaded for various branch names and produces a set of accounts

# include "AbstractFactory.h"

// Define product constructors: initialize accounts
Account::Account(double opening_balance) : m_balance(opening_balance) { }
Bank::Bank() { }

SavingsAccount::SavingsAccount(double opening_balance) : Account(opening_balance), m_account_type("Savings") { }
CheckingAccount::CheckingAccount(double opening_balance) : Account(opening_balance), m_account_type("Checking") { }
CreditAccount::CreditAccount(double opening_balance) : Account(opening_balance), m_account_type("Credit") { }

// Define functionality to return account balances
void SavingsAccount::getBalance() { std::cout << m_account_type << " balance is " << m_balance << std::endl; }
void CheckingAccount::getBalance() { std::cout << m_account_type << " balance is " << m_balance << std::endl; }
void CreditAccount::getBalance() { std::cout << m_account_type << " balance is " << m_balance << std::endl; }

// Define factory constructors: initialize names
WellsFargo::WellsFargo() : Bank(), m_bank_name("Wells Fargo") { }
BankOfAmerica::BankOfAmerica() : Bank(), m_bank_name("Bank of America") { }

// Define functionality to return derived products from derived factories
std::unique_ptr<Account> WellsFargo::openSavingsAccount(double deposit) { 
    return std::unique_ptr<Account>( new SavingsAccount(deposit) );
}

std::unique_ptr<Account> WellsFargo::openCheckingAccount(double deposit) {
    return std::unique_ptr<Account>( new CheckingAccount(deposit) );
}

std::unique_ptr<Account> WellsFargo::openCreditLine(double credit_line) {
    return std::unique_ptr<Account>( new CreditAccount(credit_line) );
}

std::unique_ptr<Account> BankOfAmerica::openSavingsAccount(double deposit) { 
    return std::unique_ptr<Account>( new SavingsAccount(deposit) );
}

std::unique_ptr<Account> BankOfAmerica::openCheckingAccount(double deposit) {
    return std::unique_ptr<Account>( new CheckingAccount(deposit) );
}

std::unique_ptr<Account> BankOfAmerica::openCreditLine(double credit_line) {
    return std::unique_ptr<Account>( new CreditAccount(credit_line) );
}

// Define functionality to get bank name
void WellsFargo::getName() { std::cout << m_bank_name; }
void BankOfAmerica::getName() { std::cout << m_bank_name; }

// Define client constructor: create client portfolio
BankPatron::BankPatron(std::unique_ptr<Bank> b, double savings, double checking, double credit) {
    m_bank = std::move(b);
    m_portfolio.push_back(m_bank->openSavingsAccount(savings));
    m_portfolio.push_back(m_bank->openCheckingAccount(checking));
    m_portfolio.push_back(m_bank->openCreditLine(credit));
}

// Define get functionality for client portfolio summary
void BankPatron::viewAccounts() {
    m_bank->getName();
    std::cout << " account summary: " << std::endl;
    for (int i = 0; i < m_portfolio.size(); ++i) { m_portfolio.at(i)->getBalance(); } 

}   

int main(int argc, char *argv[]) {

    std::cout << "Abstract factory design pattern test:" << std::endl;
    
    bankType whichBank = BOA;
    double savingsDeposit = 1000;
    double checkingDeposit = 2500;
    double creditLine = 2500;
   
    std::unique_ptr<BankPatron> patron;

    if (whichBank == WF) { 
        patron.reset( new BankPatron(std::unique_ptr<Bank>( new WellsFargo ), savingsDeposit, checkingDeposit, creditLine) );
    }
    
    else { 
        patron.reset( new BankPatron(std::unique_ptr<Bank>( new BankOfAmerica ), savingsDeposit, checkingDeposit, creditLine) );
 
    }

    patron->viewAccounts();
    
    return 0;

}
