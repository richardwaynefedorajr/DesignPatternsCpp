# include <iostream>
# include <stdio.h>
# include <string>
# include <vector>
# include <memory>

enum bankType {WF, BOA}; 

// Abstract product class
class Account {
    public:
        double balance;

        Account(double openingBalance);
        virtual ~Account() { } 
        virtual void getBalance() = 0;
};

// Abstract factory class
class Bank {
    public:
        Bank();
        virtual ~Bank() { }
        virtual Account* openSavingsAccount(double deposit) = 0;
        virtual Account* openCheckingAccount(double deposit) = 0;
        virtual Account* openCreditLine(double credit) = 0;
        virtual void getName() = 0;
};

class SavingsAccount : public Account { 
    public: 
        std::string accountType;
        SavingsAccount(double openingBalance); 
        ~SavingsAccount() { } 
        void getBalance();
};

class CheckingAccount : public Account { 
    public: 
        std::string accountType;
        CheckingAccount(double openingBalance); 
        ~CheckingAccount() { }
        void getBalance();
};

class CreditAccount : public Account { 
    public: 
        std::string accountType;
        CreditAccount(double openingBalance); 
        ~CreditAccount() { }
        void getBalance();
};

class WellsFargo : public Bank { 
    public:
        std::string bankName;
        WellsFargo();
        ~WellsFargo() { }
        Account* openSavingsAccount(double deposit);
        Account* openCheckingAccount(double deposit);
        Account* openCreditLine(double credit);
        void getName();
};

class BankOfAmerica : public Bank { 
    public:
        std::string bankName;
        BankOfAmerica();
        ~BankOfAmerica() { }
        Account* openSavingsAccount(double deposit);
        Account* openCheckingAccount(double deposit);
        Account* openCreditLine(double credit);
        void getName();
};

class BankPatron {
    private:
        Bank *bank;

    public:
        BankPatron(Bank *b, double savings, double checking, double credit);
        void viewAccounts();
        std::vector<Account*> portfolio;
};
