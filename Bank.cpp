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
        accounts.insert(pair<string,Account>(account.getAccUserName(),account));
    }


    infile.close();

}
Account Bank::OpenAccount(string fname,string lname,string UserName,float balance)
{
    //
    ofstream outfile;
    Account account(fname,lname,UserName,balance);
    accounts.insert(pair<string,Account>(account.getAccUserName(),account));

    outfile.open("Bank.data", ios::trunc);

    map<string,Account>::iterator itr;
    for(itr=accounts.begin();itr != accounts.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
    return account;
}

Account Bank::BalanceEnquiry(string Us)
{
    map<string,Account>::iterator itr= accounts.find(Us);
    return itr->second;
}


Account Bank::Deposit(string us,float amount)
{
    map<string,Account>::iterator itr=accounts.find(us);
    itr->second.Deposit(amount);
    return itr->second;
}


Account Bank::Withdraw(string us,float amount)
{
    map<string,Account>::iterator itr=accounts.find(us);
    itr->second.Withdraw(amount);
    return itr->second;
}


void Bank::CloseAccount(string us)
{
    map<string,Account>::iterator itr=accounts.find(us);
    cout <<"Account Deleted"<<itr->second;
    accounts.erase(us);
}
void Bank::ShowAllAccounts()
{
    map<string,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
    {
        cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
    }
}
Bank::~Bank()
{
    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);

    map<string,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
    {
    outfile<<itr->second;
    }
    outfile.close();
}