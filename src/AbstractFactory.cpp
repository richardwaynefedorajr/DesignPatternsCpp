# include "AbstractFactory.h"

// Initialize accounts in product constructors
Account::Account(double opening_balance) : m_balance(opening_balance) { }
Bank::Bank() { }

SavingsAccount::SavingsAccount(double opening_balance) : Account(opening_balance), m_account_type("Savings") { }
CheckingAccount::CheckingAccount(double opening_balance) : Account(opening_balance), m_account_type("Checking") { }
CreditAccount::CreditAccount(double opening_balance) : Account(opening_balance), m_account_type("Credit") { }

// Return account balance
void SavingsAccount::getBalance() { std::cout << m_account_type << " balance is " << m_balance << std::endl; }
void CheckingAccount::getBalance() { std::cout << m_account_type << " balance is " << m_balance << std::endl; }
void CreditAccount::getBalance() { std::cout << m_account_type << " balance is " << m_balance << std::endl; }

// Initialize bank in factory constructors
WellsFargo::WellsFargo() : Bank(), m_bank_name("Wells Fargo") { }
BankOfAmerica::BankOfAmerica() : Bank(), m_bank_name("Bank of America") { }

// Return derived products from derived factories
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

// Get bank name
void WellsFargo::getName() { std::cout << m_bank_name; }
void BankOfAmerica::getName() { std::cout << m_bank_name; }

// Create client portfolio in constructor
BankPatron::BankPatron(std::unique_ptr<Bank> b, double savings, double checking, double credit) {
    m_bank = std::move(b);
    m_portfolio.push_back(m_bank->openSavingsAccount(savings));
    m_portfolio.push_back(m_bank->openCheckingAccount(checking));
    m_portfolio.push_back(m_bank->openCreditLine(credit));
}

// Client portfolio summary
void BankPatron::viewAccounts() {
    m_bank->getName();
    std::cout << " account summary: " << std::endl;
    for (int i = 0; i < m_portfolio.size(); ++i) { m_portfolio.at(i)->getBalance(); } 
}
