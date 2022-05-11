#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class BankAccount
{
public:
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
    BankAccount(){}
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

class AccountsManager
{
public:
    vector<BankAccount>bankAccounts;
    /*
    bool validate(BankAccount account)
    {
        vector<string>names = strtok(account.fullName, ' ')
        if (names.size <= 4)
        {
            cout<<" you must enter at least first 4 names, please try again!"<<endl;
            return false;
        }
        return true;
    }*/
    void AddAccount()
    {
        BankAccount new_acc;
        cout<<"Please enter your fullname: ";
        cin>> new_acc.fullName;
        new_acc.fullName+=' ';
        cout<<"Please enter your address: ";
        cin>> new_acc.address;
        cout<<"Please enter your national ID: ";
        cin>> new_acc.nationalID;
        cout<<"Please enter your age: ";
        cin>> new_acc.age;
        cout<<"Please enter your account ID: ";
        cin>> new_acc.accountID;
        if(new_acc.age < 21)
        {
           cout<<"your age is less than 21, Please enter your guardian name ";
           cin>> new_acc.guardian;
           cout<<"Please enter your guardian national ID ";
           cin>> new_acc.guardianNationalID;
        }
        //initialization of account status with closed
        new_acc.status = 0;
        cout<<"Please enter your initial balance: ";
        cin>> new_acc.balance;
        cout<<"Please enter your password: ";
        cin>> new_acc.password;
        //bool accepted = validate(new_acc)
    }
};



int main()
{
    AccountsManager obj;
    obj.AddAccount();

    return 0;
}
