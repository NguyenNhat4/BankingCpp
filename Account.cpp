

#include "Account.h"
#include <iostream>
using namespace std;
Account::Account(string fname,string lname,string UserName,float balance)
{
    this->UserName=UserName;
    firstName=fname;
    lastName=lname;
    this->balance=balance;
}
void Account::Deposit(float amount)
{
    balance+=amount;
}
void Account::Withdraw(float amount)
{

    if(balance - amount < MIN_BALANCE)
        cout<< "Account's insufficient"<<endl;
    balance-=amount;
}
ofstream & operator<<(ofstream &ofs,Account &acc)
{
    ofs<<acc.UserName<<endl;
    ofs<<acc.firstName<<endl;
    ofs<<acc.lastName<<endl;
    ofs<<acc.balance<<endl;
    return ofs;
}
ifstream & operator>>(ifstream &ifs,Account &acc)
{
    ifs>>acc.UserName;
    ifs>>acc.firstName;
    ifs>>acc.lastName;
    ifs>>acc.balance;
    return ifs;

}
ostream & operator<<(ostream &os,Account &acc)
{
    os<<"First Name:"<<acc.getFirstName()<<endl;
    os<<"Last Name:"<<acc.getLastName()<<endl;
    os<<"UserName:"<<acc.getAccUserName()<<endl;
    os<<"Balance:"<<acc.getBalance()<<endl;
    return os;
}
