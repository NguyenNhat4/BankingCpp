//
// Created by minhn on 10/17/2023.
//

#ifndef BANKINGSYSTEM_ACCOUNT_H
#define BANKINGSYSTEM_ACCOUNT_H
#include<string>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#define MIN_BALANCE 500
using namespace std;


class Account
{
private:
    string UserName;
    string firstName;
    string lastName;
    float balance;
public:

    Account(){}
    Account(string fname,string lname,string UserName,float balance);
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    string getAccUserName(){return UserName;}
    float getBalance(){return balance;}
    void Deposit(float amount);
    void Withdraw(float amount);

    friend ofstream & operator<<(ofstream &ofs,Account &acc);
    friend ifstream & operator>>(ifstream &ifs,Account &acc);
    friend ostream & operator<<(ostream &os,Account &acc);
};



#endif //BANKINGSYSTEM_ACCOUNT_H
