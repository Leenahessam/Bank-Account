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

    BankAccount() {}

    BankAccount(string fullName, string address, string nationalID, int age, string accountID, string guardian, string guardianNationalID, int status, float balance, string password)
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
    vector<BankAccount> bankAccounts;

    AccountsManager() {}
    bool validate(BankAccount account)
    {
        cout << account.fullName.size() << endl;
        // checking validation of username, must have at least the first 4 names
        int count = 0;
        for (int i = 0; i < account.fullName.size(); i++)
        {
            if (account.fullName[i] == ' ')
                count++;
        }
        if (count < 4)
            return false;
        cout << "true1" << endl;

        // checking validation of national id, its length must be equal 14
        if (account.nationalID.size() != 14 || ((account.guardianNationalID != "") && (account.guardianNationalID.size() != 14)))
            return false;

        cout << "true2" << endl;

        return true;
    }
    void addAccount()
    {
        BankAccount new_acc;
        cout << "Please enter your fullname: ";
        getline(cin, new_acc.fullName);
        new_acc.fullName += ' ';
        cout << "Please enter your address: ";
        getline(cin, new_acc.address);
        cout << "Please enter your national ID: ";
        getline(cin, new_acc.nationalID);
        cout << "Please enter your age: ";
        cin >> new_acc.age;
        new_acc.accountID = new_acc.nationalID;
        new_acc.guardian = "";
        new_acc.guardianNationalID = "";
        if (new_acc.age < 21)
        {
            cout << "your age is less than 21, Please enter your guardian name ";
            getline(cin, new_acc.guardian);
            getline(cin, new_acc.guardian);
            cout << "Please enter your guardian national ID ";
            getline(cin, new_acc.guardianNationalID);
        }
        // initialization of account status with closed
        new_acc.status = 0;
        cout << "Please enter your initial balance: ";
        cin >> new_acc.balance;
        new_acc.password = new_acc.nationalID;
        bool accepted = validate(new_acc);
        cout << "processing..." << endl;
        if (accepted)
        {
            cout << "Account is created successfully!" << endl;
            // activate account
            new_acc.status = 1;
            bankAccounts.push_back(new_acc);
        }

        else
            cout << "Please check these instructions and try again \nFull Name >= 4\nNational ID and guardian national ID = 14 digits\n"
                 << endl;
    }

    bool changeAccountStatus(string accountID, int newStatus)
    {
        for (int i = 0; i < bankAccounts.size(); i++)
        {
            if (bankAccounts[i].accountID == accountID)
            {
                bankAccounts[i].status = newStatus;
                return true;
            }
        }
        return false;
    }

    void printAccounts()
    {
        for (int i = 0; i < bankAccounts.size(); i++)
        {
            cout << "Account " << i + 1 << endl;
            cout << "Account ID " << bankAccounts[i].accountID << endl;
            cout << "Username " << bankAccounts[i].fullName << endl;
            cout << "Address " << bankAccounts[i].address << endl;
            cout << "National ID " << bankAccounts[i].nationalID << endl;
            cout << "Age" << bankAccounts[i].age << endl;
            cout << "guardian " << bankAccounts[i].guardian << endl;
            cout << "guardian national ID " << bankAccounts[i].guardianNationalID << endl;
            cout << "Balance " << bankAccounts[i].balance << endl;
        }
    }

    // Hadeer functions

    int findAccountIndex(string accountID)
    {
        for (int i = 0; i < bankAccounts.size(); i++)
            if (bankAccounts[i].accountID == accountID)
                return i;

        return -1;
    }

    bool isBalanceBigger(int accountIdx, float amount)
    {
        if (bankAccounts[accountIdx].balance > amount)
            return true;

        return false;
    }

    /// Gets Account ID from user for 3 trials, or treminate program
    int getUserAccountIdx()
    {
        int trials = 3;
        string accountID;
        int accountIdx = -1;

        while (trials > 0)
        {
            if (accountIdx == -1)
            {
                if (trials == 3)
                    cout << "Please enter account ID: ";
                else
                    cout << "Wrong account ID\nPlease enter valid account ID: ";

                getline(cin, accountID);
                accountIdx = findAccountIndex(accountID);

                trials--;
            }
            else
            {
                return accountIdx;
            }
        }

        cout << "Wrong account ID";
        exit(0);
        return 0;
    }

    // returns password
    string checkGetPassword(int accountIdx)
    {
        int trials = 3;
        string password;

        while (trials > 0)
        {

            if (trials == 3)
                cout << "Please enter password: ";
            else
                cout << "Wrong password\nPlease enter your password: ";

            getline(cin, password);

            if (password == bankAccounts[accountIdx].password)
                return password;

            trials--;
        }

        cout << "Wrong Password";
        exit(0);
        return " ";
    }

    void makeTransactionClient()
    {
        int senderIdx, recieverIdx;
        string senderAccountID, recieverAccountID, senderPassword;
        float amount;

        // get transactions data
        cout << "Please enter your account ID: ";
        getline(cin, senderAccountID);
        senderIdx = getUserAccountIdx();

        cout << "Please enter your password: ";
        getline(cin, senderPassword);

        cout << "Please enter reciever account ID: ";
        getline(cin, recieverAccountID);
        recieverIdx = getUserAccountIdx();

        cout << "Please enter amount of money: ";
        cin >> amount;

        // process transaction
        if (isBalanceBigger(senderIdx, amount))
        {
            bankAccounts[senderIdx].balance -= amount;
            bankAccounts[recieverIdx].balance += amount;
            cout << "Transaction done successfully" << endl;
        }
        else
        {
            cout << "Balance is not sufficient     X" << endl;
        }
    }

    void changePassword()
    {
        int accountIdx;
        string accountID, oldPassword, newPassword;

        accountIdx = getUserAccountIdx();

        oldPassword = checkGetPassword(accountIdx);

        cout << "Please enter your new password: ";
        getline(cin, newPassword);
        bankAccounts[accountIdx].password = newPassword;

        cout << "Password changed successfully!" << endl;
    }

    void getCash()
    {

        int accountIdx;
        string password;
        float amount;

        accountIdx = getUserAccountIdx();
        password = checkGetPassword(accountIdx);

        while (true)
        {
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (bankAccounts[accountIdx].balance <= amount)
                cout << "ERROR: Balance is not enough!\nCurrent Balance : " << bankAccounts[accountIdx].balance << endl;

            else
            {
                bankAccounts[accountIdx].balance -= amount;
                cout << "Successful operation!\nYour Balance now : " << bankAccounts[accountIdx].balance << endl;
                return;
            }
        }
    }
};

/*
Hadeer comments
accountsManager function should be static
-each function displays its interactions and do all procssing
-validate user accounts in make transaction
*/

/*
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
                    cout << "please, enter bank account ID " << endl;
                    getline(cin, bankAccountID);
                    cout << "enter new status" << endl;
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
*/
int main()
{
    // Main_Menu_Admin();
    AccountsManager a;
    BankAccount b("jhskhs", "sjs", "ksl", 67, "187", " ", " ", 1, 500, "1234");

    a.bankAccounts.push_back(b);
    // a.addAccount();
    a.printAccounts();
    a.getCash();

    return 0;
}
