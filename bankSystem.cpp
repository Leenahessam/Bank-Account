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
    bool validate(BankAccount account)
    {
        //checking validation of username, must have at least the first 4 names
        int count = 0;
        for(int i=0; i<account.fullName.size(); i++)
        {
            if(account.fullName[i] == ' ')
                count++;
        }
        if(count < 4)
            return false;
        //checking validation of national id, its length must be equal 14
        if(account.nationalID.size() != 14 || ((account.guardianNationalID!="") && (account.guardianNationalID.size() != 14)))
            return false;
        return true;
    }
    void addAccount()
    {
        BankAccount new_acc;
        cout<<"Please enter your fullname: ";
        getline(cin,new_acc.fullName) ;
        new_acc.fullName+=' ';
        cout<<"Please enter your address: ";
        getline(cin,new_acc.address);
        cout<<"Please enter your national ID: ";
        getline(cin,new_acc.nationalID);
        cout<<"Please enter your age: ";
        cin>>new_acc.age;
        new_acc.accountID = new_acc.nationalID ;
        new_acc.guardian = "";
        new_acc.guardianNationalID = "";
        if(new_acc.age < 21)
        {
           cout<<"your age is less than 21, Please enter your guardian name ";
           getline(cin,new_acc.guardian) ;
           getline(cin,new_acc.guardian) ;
           cout<<"Please enter your guardian national ID ";
           getline(cin,new_acc.guardianNationalID);
        }
        //initialization of account status with closed
        new_acc.status = 0;
        cout<<"Please enter your initial balance: ";
        cin>> new_acc.balance;
        new_acc.password = new_acc.nationalID;
        bool accepted = validate(new_acc);
        cout<<"processing..."<<endl;
        if(accepted){
            cout<<"Account is created successfully!"<<endl;
            //activate account
            new_acc.status = 1;
            bankAccounts.push_back(new_acc);
        }

        else
            cout<<"Please check these instructions and try again \nFull Name >= 4\nNational ID = 14 digits"<<endl;

    }
    bool changeAccountStatus(string accountID, int newStatus){
        for(int i = 0; i < bankAccounts.size(); i++)
        {
            if(bankAccounts[i].accountID == accountID){
               bankAccounts[i].status = newStatus;
               return true;
            }
        }
        return false;
    }
    void printAccounts()
    {
        for(int i = 0; i < bankAccounts.size(); i++)
        {
            cout<<"Account "<<i+1<<endl;
            cout<<"Account ID "<<bankAccounts[i].accountID<<endl;
            cout<<"Username "<<bankAccounts[i].fullName<<endl;
            cout<<"Address "<<bankAccounts[i].address<<endl;
            cout<<"National ID "<<bankAccounts[i].nationalID<<endl;
            cout<<"Age"<<bankAccounts[i].age<<endl;
            cout<<"guardian "<<bankAccounts[i].guardian<<endl;
            cout<<"guardian national ID "<<bankAccounts[i].guardianNationalID<<endl;
            cout<<"Balance "<<bankAccounts[i].balance<<endl;
       }
    }
};



void Main_Menu_Admin()
{
    int choice;
    string existing_id;
    int account_choice;
    AccountsManager obj;
    do
    {
        cout << "1- Create a new Account.\n"
             << "2- Open an Existing Account.\n"
             << "3- Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // create new bank account
            obj.addAccount();
            break;
        case 2:
            cout << "Enter Account ID.\n";
            cin >> existing_id;
            // search for account
            cout << "21- Make Transaction.\n"
                 << "22- Change Account Status.\n"
                 << "23- Get Cash.\n"
                 << "24- Deposite in an Account.\n"
                 << "25- Return To Main Menu.\n";
            cin >> account_choice;
            do
            {
                switch (account_choice)
                {
                case 21:
                    // make transaction
                    break;
                case 22:
                    // Change account status
                    string bankAccountID;
                    int status;
                    cout<<"please, enter bank account ID "<<endl;
                    getline(cin,bankAccountID);
                    cout<<"enter new status"<<endl;
                    obj.changeAccountStatus(bankAccountID, status);
                    break;
                case 23:
                    // get cash
                    break;
                case 24:
                    // deposite in a account
                    break;
                case 25:
                    // return to main menu

                    break;
                default:
                    cout << "Error in Validation.\n";
                    break;
                }
            } while (account_choice != 25);
        case 3:
            cout << "Good Bye.\n";

            break;
        default:
            cout << "ERROR!!!!!!.\n";
            break;
        }
    } while (choice != 3);
}

int main()
{
    Main_Menu_Admin();
    return 0;
}
