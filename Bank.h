
#ifndef BANKINGSYSTEM_BANK_H
#define BANKINGSYSTEM_BANK_H
#include "Account.h"
class Bank
{
private:
    map<long,Account> accounts;
public:
    Bank();
    Account OpenAccount(string fname,string lname,string UserName, float balance);
    Account BalanceEnquiry(string UserName);
    Account Deposit(string UserName,float amount);
    Account Withdraw(string UserName,float amount);
    void CloseAccount(string UserName);
    void ShowAllAccounts();
    ~Bank();
};


#endif //BANKINGSYSTEM_BANK_H
