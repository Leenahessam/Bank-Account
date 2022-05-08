#include <iostream>
#include <string.h>
using namespace std;

class BankAccount
{
    string fullName;
    string address;
    string nationalID;
    int age;
    string accountID;
    string guardian;
    string guardianNationalID;
    int status;
    float balance;
    string password;

public:
    BankAccount(string fullName, string address, string nationalID, int age, string guardian, string guardianNationalID, int status, float balance, string password)
    {
        this->fullName = fullName;
        this->address = address;
        this->nationalID = nationalID;
        this->age = age;
        this->accountID = accountID;
        this->guardian = guardian;
        this->guardianNationalID = guardianNationalID;
        this->status = status;
        this->balance = balance;
        this->password = password;
    }
};

int main()
{
    // BankAccount a = new BankAccount()
    return 0;
}