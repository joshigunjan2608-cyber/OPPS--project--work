#include <iostream>
using namespace std;

class BankAccount
{
private:
    int balance;

public:
    void setBalance(int b)
    {
        balance = b;
    }

    void showBalance()
    {
        cout << balance;
    }
};

class SavingAccount : public BankAccount
{
public:
    void accountType()
    {
        cout << "\nSaving Account";
    }
};

int main()
{
    SavingAccount account;

    account.setBalance(5000);
    account.accountType();
    account.showBalance();

    return 0;
}