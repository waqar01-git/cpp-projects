// My programme flow:
//   Insert card
//  ️ Enter PIN (once)
//  ️ If PIN correct → show menu
//   Perform multiple actions
//   Logout

#include <iostream>
#include <string>
#include <windows.h> //for Sleep use in my programme
#include <stdlib.h>
#include <time.h>

using namespace std;
class BankAccount
{
    int pin;
    int accNo;
    string name;
    int balance;
    int chance;

public:
    BankAccount(int account, string name, int balance, int pin, int chance)
    {
        accNo = account;
        this->name = name;
        this->balance = balance;
        this->pin = pin;
        this->chance = chance;
    }
    void deposit(int deposit);
    void withdraw(int withdraw);
    void check();
    void display();
    void choice(int n);
    bool checkPin();
    int insertCard();
    void loader_dot();
    void loader_dot_percentage();
};
void BankAccount ::loader_dot()
{
    int count = 0;
    srand(time(NULL));
    count = (rand() % 5 + 1); // range 1-5
    cout << "Processing, please wait ";

    for (int i = 0; i < count; i++) // max will be 4 and min will be 1
    {
        for (int j = 0; j < 6; j++)
        {
            cout << ".";
            Sleep(250);
        }
        cout << "\b\b\b\b\b\b";
        cout << "      ";       // it overwrite the 6 backspaces.It help me erace previous 6 dots.
        cout << "\b\b\b\b\b\b"; // now it move back to 6 spaces again for next animation
    }
    cout << "\n";
}
void BankAccount ::loader_dot_percentage()
{
    char load[4] = {'|', '/', '-', '\\'};
    int count = 0;
    srand(time(0));
    count = (rand() % 5 + 1); // range 1-5
    cout << "Processing, please wait ";

    for (int i = 0; i < count; i++) // max will be 4 and min will be 1
    {
        for (int j = 0; j < 4; j++)
        {
            cout << load[j];
            Sleep(250);
            cout << "\b";
            cout << " ";  // it overwrite the 6 backspaces.It help me erase previous 6 dots.
            cout << "\b"; // now it move back to 6 spaces again for next animation
        }
    }
    cout << "\n";
}

void BankAccount ::deposit(int deposit)
{
    int action;
    cout << "Deposit cash in right top box of machine\n";
    cout << "Enter 1 after done: ";
    cin >> action;
    if (action == 1)
    {
        loader_dot();
        if (deposit < 0)
        {
            cout << "Sorry! This amount is not deposited" << endl;
        }
        else if (deposit > 0)
        {
            balance += deposit;
            cout << "You deposit " << deposit << " rupees sucessfully" << endl;
        }
        else
            cout << "Invalid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
}

void BankAccount ::withdraw(int withdraw)
{
    loader_dot();
    if (withdraw > balance)
    {
        cout << "Sorry! " << withdraw << " rupees is not in your account" << endl;
    }
    else if (withdraw < balance && withdraw > 0 || withdraw == balance)
    {

        cout << "Take your cash\n";
        cout << withdraw << " rupees is withdraw sucessfully" << endl;
        balance -= withdraw;
    }
    else
        cout << "Invalid" << endl;
}
void BankAccount ::check()
{

    char ch;
    cout << "Want to check account balance?((y or n): )" << endl;
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
    {
        cout << "Your balance is :" << balance << endl;
    }
    else if (ch == 'N' || ch == 'n')
    {
        cout << "Thanks for using ATM" << endl;
    }
    else
        cout << "Enter valid choice:" << endl;
}
void BankAccount ::display()
{
    loader_dot();
    cout << "Account Owner: " << name << endl;
    cout << "Account id " << accNo << endl;
    cout << "Balance: " << balance << endl;
}
bool BankAccount ::checkPin()
{
    int enteredpin;

    cout << "Enter pin: ";
    while (chance > 0)
    {
        cin >> enteredpin;
        cout << "Verifying PIN ..." << endl;
        loader_dot();

        if (enteredpin == pin)
        {
            cout << "Correct pin\n\nAccess granted" << endl;
            return true;
        }
        else
        {
            cout << "Wrong pin " << --chance << " more chance(s) left" << endl
                 << "Otherwise permission will be denied\nTry again: " << endl;
        }
    }
    cout << "Sorry permission denied\n";
    return false;
}
void BankAccount ::choice(int n)
{
    int depositAmount;
    int withdrawAmount;

    switch (n)
    {
    case 0:
        cout << "Card is coming out ..." << endl;
        loader_dot_percentage();
        cout << "Take your card\n";
        Sleep(1000);
        cout << "logout sucessfull" << endl;
        cout << "Thanks for using me" << endl;
        break;
    case 1:
    {
        cout << "Enter amount to deposit: ";
        cin >> depositAmount;
        deposit(depositAmount);
    }
    break;

    case 2:
    {
        cout << "Enter amount to Withdraw: ";
        cin >> withdrawAmount;
        withdraw(withdrawAmount);
    }
    break;

    case 3:
        check();
        break;

    case 4:
        display();
        break;

    default:
        cout << "Enter valid choice" << endl;
    }
}
int BankAccount ::insertCard()
{
    int insert;
    cout << "=====Welcome to ATM=====\nInsert your card" << endl;
    cout << "1 for insert card\n0 for nothing" << endl;
    cout << "->";
    cin >> insert;
    if (insert == 1)
    {
        cout << "Processing your card ..." << endl;
        loader_dot_percentage();
        return 1;
    }
    else if (insert == 0)
    {
        return 0;
    }
    else
    {
        cout << "Invalid Card\n";
        return 0;
    }
}
int main()
{
    int choice;
    BankAccount account1(1199, "Hanan Qaisar", 0, 1234, 3);
    if (account1.insertCard())
    {
        if (!account1.checkPin())
        {
            return 0;
        }
        else
        {
            cout << "|==================|\n";
            cout << "|     ATM MENU     |\n";
            cout << "|==================|\n";
            cout << "| 1. Deposit       |\n";
            cout << "| 3. Check Balance |\n";
            cout << "| 4. Display Info  |\n";
            cout << "| 0. Exit          |\n";
            cout << "|==================|\n";
            cout << "-> ";

            do
            {
                cin >> choice;
                if (choice < 0 || choice > 4)
                {
                    cout << "Enter valid Choice" << endl;
                }
                else
                {
                    account1.choice(choice);
                    if (choice != 0)
                    {
                        cout << "Choose next option:" << endl
                             << "->";
                    }
                }
            } while (choice != 0);
        }

        return 0;
    }
}