
#ifndef BANKINGSYSTEM_BANK_H
#define BANKINGSYSTEM_BANK_H
#include "Account.h"
class Bank
{
private:
    map<long,Account> accounts;
public:
    Bank();
    Account OpenAccount(string fname,string lname,float balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber,float amount);
    Account Withdraw(long    accountNumber,float amount);
    void CloseAccount(long accountNumber);
    void ShowAllAccounts();
    ~Bank();
};


#endif //BANKINGSYSTEM_BANK_H
