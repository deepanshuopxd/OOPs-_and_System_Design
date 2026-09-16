#include <iostream> 
#include <vector> 
#include <typeinfo> 
#include <stdexcept> 

using namespace std; 


/*
LSP: Liskov Substitution Principle

Full Form:
L → Liskov
S → Substitution
P → Principle

Definition:
Derived (child) classes must be substitutable for their base (parent) classes 
without altering the correctness of the program.

In simple terms:
If a program works with a base class, it should work the same way 
when a derived class object is used.

Key Idea:
Child class should NOT break expectations set by parent class.
*/


// Base abstraction: only deposit behavior
class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
};


// Extended abstraction: deposit + withdraw
class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};


/*
SavingAccount follows LSP:

- It supports deposit (as expected by DepositOnlyAccount)
- It supports withdraw (as expected by WithdrawableAccount)
- Does not break any contract
*/

class SavingAccount : public WithdrawableAccount {
private:
    double balance;

public:
    SavingAccount() {  
        balance = 0;  
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};


/*
CurrentAccount also follows LSP:

- Same behavior contract as WithdrawableAccount
- Can replace base class safely
*/

class CurrentAccount : public WithdrawableAccount {
private:
    double balance;

public:
    CurrentAccount() {  
        balance = 0;  
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};


/*
FixedTermAccount follows LSP correctly:

- It inherits ONLY from DepositOnlyAccount
- It does NOT support withdraw

Important:
If we had forced it to inherit WithdrawableAccount and then throw error in withdraw(),
that would violate LSP.
*/

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;

public:
    FixedTermAccount() {  
        balance = 0;  
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};


/*
BankClient uses abstraction properly:

- Works with base classes (DepositOnlyAccount, WithdrawableAccount)
- Does not care about concrete types

This ensures:
Polymorphism + LSP compliance
*/

class BankClient {
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

public:
    BankClient(
        vector<WithdrawableAccount*> withdrawableAccounts,  
        vector<DepositOnlyAccount*> depositOnlyAccounts
    ) {
        this->withdrawableAccounts = withdrawableAccounts;  
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions() {

        // Works for ALL withdrawable accounts
        // LSP: any child of WithdrawableAccount behaves correctly
        for (WithdrawableAccount* acc : withdrawableAccounts) {
            acc->deposit(1000);
            acc->withdraw(500);  
        }

        // Works for ALL deposit-only accounts
        // LSP: any child of DepositOnlyAccount behaves correctly
        for (DepositOnlyAccount* acc : depositOnlyAccounts) {
            acc->deposit(5000);
        }
    }
};


int main() {

    // Only accounts that support withdraw go here
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    // Only deposit-only accounts go here
    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();

    return 0;
}