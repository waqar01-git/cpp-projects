#include <iostream>
using namespace std;

class BankAccount
{
private:
    int AccountNo;
    double Balance;

public:
    // parameterized constructor
    BankAccount(int AccountNo, double Balance)
    {
        this->AccountNo = AccountNo;
        this->Balance = Balance;
    }

    // copy constructor
    BankAccount(const BankAccount &B1)
    {
        this->AccountNo = B1.AccountNo;
        this->Balance = B1.Balance;
    }
    void deposit(int n)
    {

        if (n > 0)
        {
            Balance += n;
        }
        else
        {
            cout << "Invalid Amount" << endl;
        }
    }
    bool withdraw(int amount)
    {
        if (amount > 0 && amount <= Balance)
        {
            Balance -= amount;
            return true;
        }
        else

            return false;
    }
    void Transfer(BankAccount *receiver, double Amount)
    {

        this->Balance += Amount;     // sender
        receiver->Balance -= Amount; // Receiver
    }
    void display()
    {

        cout << "       ACCOUNT INFORMATION" << endl;
        cout << "Account Number:" << AccountNo << endl;
        cout << "Balance:" << Balance << endl;
    }
};

int main()
{
    BankAccount *B1 = new BankAccount(1234, 55000.978);
    BankAccount *B2 = new BankAccount(5678, 60000.788);

    BankAccount B3 = *B1;

    (*B1).deposit(1000);

    (*B2).withdraw(2000);

    if ((*B2).withdraw(2000))
    {
        cout << "Transaction Successful" << endl;
    }
    else
        cout << "not successful" << endl;

    (*B1).Transfer(B2, 1000); // B1 is sending money while B2 is receiving it.
    (*B1).display();
    (*B2).display();

    return 0;
}
