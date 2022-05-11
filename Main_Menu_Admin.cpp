#include <iostream>
#include <string.h>
#include bankAccount.cpp;
using namespace std;

void Main_Menu_Admin()
{
    int choice;
    string existing_id;
    int account_choice;
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
int findAccountIndex(string accountID)
{
    for (int i = 0; i < bankAccounts.size(); i++)
        if (bankAccounts[i].accountID == accountID)
            return i;

    return -1;
}

float getCash(string accountID, float cash)
{
    for (int i = 0; i < bankAccounts.size(); i++)
    {
        if (bankAccounts[i].accountID == accountID && bankAccounts[i].status == 1)
        {
            if (bankAccounts[i].balance > cash)
            {
                bankAccounts[i].balance -= cash;
                return bankAccounts[i].balance;
            }
        }
    }
    return -1;
}

float depositeInAccount(string accountID, float cash)
{
    for (int i = 0; i < bankAccounts.size(); i++)
    {
        if (bankAccounts[i].accountID == accountID && bankAccounts[i].status == 1)
        {
            bankAccounts[i].balance += cash;
            return bankAccounts[i].balance;
        }
    }
    return -1;
}

bool makeTransaction(string senderAccountID, string reciverAccountID, float cash)
{
    for (int i = 0; i < bankAccounts.size(); i++)
    {
        if (bankAccounts[i].senderAccountID == accountID && bankAccounts[i].status == 1 && bankAccounts[i].balance > cash)
        {
            for (int j = 0; i < bankAccounts.size(); i++)
            {
                if (bankAccounts[i].senderAccountID == accountID && bankAccounts[i].status == 1)
                {
                    bankAccounts[i].balance -= cash;
                    bankAccounts[j].balance += cash;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    Main_Menu_Admin();
    return 0;
}