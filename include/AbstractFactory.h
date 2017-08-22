# include <iostream>
# include <stdio.h>
# include <string>
# include <vector>
# include <memory>

enum bankType {WF, BOA}; 

// Abstract product class declaration
class Account {
    public:
        double m_balance;
        Account(double opening_balance);
        virtual ~Account() { } 
        virtual void getBalance() = 0;
};

// Abstract factory class declaration
class Bank {
    public:
        Bank();
        virtual ~Bank() { }
        virtual std::unique_ptr<Account> openSavingsAccount(double deposit) = 0;
        virtual std::unique_ptr<Account> openCheckingAccount(double deposit) = 0;
        virtual std::unique_ptr<Account> openCreditLine(double credit) = 0;
        virtual void getName() = 0;
};

// Derived product class declarations
class SavingsAccount : public Account { 
    public: 
        std::string m_account_type;
        SavingsAccount(double opening_balance); 
        ~SavingsAccount() { } 
        void getBalance();
};

class CheckingAccount : public Account { 
    public: 
        std::string m_account_type;
        CheckingAccount(double opening_balance); 
        ~CheckingAccount() { }
        void getBalance();
};

class CreditAccount : public Account { 
    public: 
        std::string m_account_type;
        CreditAccount(double opening_balance); 
        ~CreditAccount() { }
        void getBalance();
};

// Derived factory class declarations
class WellsFargo : public Bank { 
    public:
        std::string m_bank_name;
        WellsFargo();
        ~WellsFargo() { }
        std::unique_ptr<Account> openSavingsAccount(double deposit);
        std::unique_ptr<Account> openCheckingAccount(double deposit);
        std::unique_ptr<Account> openCreditLine(double credit);
        void getName();
};

class BankOfAmerica : public Bank { 
    public:
        std::string m_bank_name;
        BankOfAmerica();
        ~BankOfAmerica() { }
        std::unique_ptr<Account> openSavingsAccount(double deposit);
        std::unique_ptr<Account> openCheckingAccount(double deposit);
        std::unique_ptr<Account> openCreditLine(double credit);
        void getName();
};

// Client interface declaration
class BankPatron {
    private:
        std::unique_ptr<Bank> m_bank;

    public:
        BankPatron(std::unique_ptr<Bank> b, double savings, double checking, double credit);
        void viewAccounts();
        std::vector< std::unique_ptr<Account> > m_portfolio;
};
