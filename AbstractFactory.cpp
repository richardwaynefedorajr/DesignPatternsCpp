# include "AbstractFactory.h"

// NEED TO PASS ACCOUNT NAME THROUGH BASE CLASS CONSTRUCTOR

Account::Account(double openingBalance) : balance(openingBalance) { }
Bank::Bank() { }

SavingsAccount::SavingsAccount(double openingBalance) : Account(openingBalance), accountType("Savings") { }
CheckingAccount::CheckingAccount(double openingBalance) : Account(openingBalance), accountType("Checking") { }
CreditAccount::CreditAccount(double openingBalance) : Account(openingBalance), accountType("Credit") { }

void SavingsAccount::getBalance() { std::cout << accountType << " balance is " << balance << std::endl; }
void CheckingAccount::getBalance() { std::cout << accountType << " balance is " << balance << std::endl; }
void CreditAccount::getBalance() { std::cout << accountType << " balance is " << balance << std::endl; }

WellsFargo::WellsFargo() : Bank(), bankName("Wells Fargo") { }
BankOfAmerica::BankOfAmerica() : Bank(), bankName("Bank of America") { }

Account* WellsFargo::openSavingsAccount(double deposit) { 
    std::unique_ptr<Account> account;
    account = std::unique_ptr<Account>(new SavingsAccount(deposit));
    return account.release();
}

Account* WellsFargo::openCheckingAccount(double deposit) {
    std::unique_ptr<Account> account;
    account = std::unique_ptr<Account>(new CheckingAccount(deposit));
    return account.release();
}

Account* WellsFargo::openCreditLine(double creditLine) {
    std::unique_ptr<Account> account;
    account = std::unique_ptr<Account>(new CreditAccount(creditLine));
    return account.release();
}

Account* BankOfAmerica::openSavingsAccount(double deposit) { 
    std::unique_ptr<Account> account;
    account = std::unique_ptr<Account>(new SavingsAccount(deposit));
    return account.release();
}

Account* BankOfAmerica::openCheckingAccount(double deposit) {
    std::unique_ptr<Account> account;
    account = std::unique_ptr<Account>(new CheckingAccount(deposit));
    return account.release();
}

Account* BankOfAmerica::openCreditLine(double creditLine) {
    std::unique_ptr<Account> account;
    account = std::unique_ptr<Account>(new CreditAccount(creditLine));
    return account.release();
}

void WellsFargo::getName() { std::cout << bankName; }
void BankOfAmerica::getName() { std::cout << bankName; }

BankPatron::BankPatron(Bank *b, double savings, double checking, double credit) {
    bank = b;
    portfolio.push_back(bank->openSavingsAccount(savings));
    portfolio.push_back(bank->openCheckingAccount(checking));
    portfolio.push_back(bank->openCreditLine(credit));
}

void BankPatron::viewAccounts() {
    bank->getName();
    std::cout << " account summary: " << std::endl;
    for (int i = 0; i < portfolio.size(); ++i) { portfolio.at(i)->getBalance(); } 
}
