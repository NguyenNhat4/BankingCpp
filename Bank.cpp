#include <iostream>
#include "Bank.h"
using namespace std;

Bank::Bank()
{
    Account account;
    ifstream infile;
    infile.open("Bank.data");
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    while(!infile.eof())
    {
        infile>>account;
        accounts.insert(pair<long,Account>(account.getAccUserName(),account));
    }


    infile.close();

}
Account Bank::OpenAccount(string fname,string lname,string UserName,float balance)
{
    ofstream outfile;
    Account account(fname,lname,UserName,balance);
    accounts.insert(pair<long,Account>(account.getAccUserName(),account));

    outfile.open("Bank.data", ios::trunc);

    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
    return account;
}

Account Bank::BalanceEnquiry(string Us)
{
    map<long,Account>::iterator itr= accounts.find(Us);
    return itr->second;
}


Account Bank::Deposit(string UserName,float amount)
{
    map<long,Account>::iterator itr=accounts.find(UserName);
    itr->second.Deposit(amount);
    return itr->second;
}


Account Bank::Withdraw(long accountNumber,float amount)
{
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    itr->second.Withdraw(amount);
    return itr->second;
}


void Bank::CloseAccount(string us)
{
    map<long,Account>::iterator itr=accounts.find(us);
    cout <<"Account Deleted"<<itr->second;
    accounts.erase(us);
}
void Bank::ShowAllAccounts()
{
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
    {
        cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
    }
}
Bank::~Bank()
{
    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);

    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
}