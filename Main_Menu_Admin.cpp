#include <iostream>
#include <string.h>
#include bankAccount.cpp;
using namespace std;

void Main_Menu_Admin()
{
    int choice;
    string existing_id;
    string resever_id;
    int account_choice;
    float cash;
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
                    cout << "Enter Reciver Account ID.\n";
                    cin >> resever_id;
                    cout << "Enter Amount of Money To Be Transfared.\n";
                    cin >> cash;
                    bool result = makeTransaction(existing_id, resever_id, cash);
                    if (result == true)
                    {
                        cout << "Transaction Done .\n";
                    }
                    else
                    {
                        cout << "Something Went Wronge Try Again.\n";
                    }
                    break;
                case 22:
                    // Change account status
                    break;
                case 23:
                    // get cash
                    cout << "Enter Amount of Money To Withdraw.\n";
                    cin >> cash;
                    float result = getCash(existing_id, cash);
                    if (result != -1)
                    {
                        cout << "New Balance =  %f", result;
                    }
                    else
                    {
                        cout << "Something Went Wronge Try Again.\n";
                    }

                    break;
                case 24:
                    // deposite in a account
                    cout << "Enter Amount of Money To Deposite.\n";
                    cin >> cash;
                    float result = depositeInAccount(existing_id, cash);
                    if (result != -1)
                    {
                        cout << "New Balance =  %f", result;
                    }
                    else
                    {
                        cout << "Something Went Wronge Try Again.\n";
                    }

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
    int idx = findAccountIndex(accountID);
    if (bankAccounts[idx].accountID == accountID && bankAccounts[idx].status == 1)
    {
        if (bankAccounts[idx].balance > cash)
        {
            bankAccounts[idx].balance -= cash;
            return bankAccounts[idx].balance;
        }
    }

    return -1;
}

float depositeInAccount(string accountID, float cash)
{
    int idx = findAccountIndex(accountID);
    if (bankAccounts[idx].status == 1)
    {
        bankAccounts[idx].balance += cash;
        return bankAccounts[idx].balance;
    }
    return -1;
}

bool makeTransaction(string senderAccountID, string reciverAccountID, float cash)
{
    int send_idx = findAccountIndex(senderAccountID);
    int reseve_idx = findAccountIndex(reciverAccountID);
    if (bankAccounts[send_idx].status == 1 && bankAccounts[send_idx].balance > cash)
    {
        if (bankAccounts[reseve_idx].status == 1)
        {
            bankAccounts[send_idx].balance -= cash;
            bankAccounts[reseve_idx].balance += cash;
            return true;
        }
    }
    return false;
}

int main()
{
    Main_Menu_Admin();
    return 0;
}