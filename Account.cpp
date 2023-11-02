

#include "Account.h"
#include <iostream>
using namespace std;
Account::Account(string fname,string lname,string UserName,float blance)
{
    this->UserName=UserName;
    firstName=fname;
    lastName=lname;
    balance=blance;
    h_list  = new HISTORY_TRANSITION_LIST(balance,"Create account");
}
void Account::Deposit(float amount)
{
    balance+=amount;
    h_list->fill_In_History_info(amount,"deposit");
}
void Account::Withdraw(float amount)
{
    if(balance - amount < MIN_BALANCE) {
        cout << "Account's insufficient" << endl;
     return;
    }
    balance-=amount;
    h_list->fill_In_History_info(amount,"withdraw");
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
