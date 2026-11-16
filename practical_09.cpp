#include <iostream>
#include <exception>
using namespace std;

class BankException : public exception {
};

class InsufficientBalance : public BankException {
public:
    const char* what() const noexcept override {
        return "Insufficient Balance";
    }
};

class InvalidAmount : public BankException {
public:
    const char* what() const noexcept override {
        return "Invalid Amount";
    }
};

class Bank {
    int balance = 500;

public:
    void withdraw(int amount) {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > balance)
            throw InsufficientBalance();

        balance = balance - amount;

        cout << "Withdrawal Successful" << endl;
        cout << "Remaining Balance: " << balance;
    }
};

int main() {
    Bank b;
    int amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try {
        b.withdraw(amount);
    }
    catch (const InvalidAmount& e) {
        cout << e.what();
    }
    catch (const InsufficientBalance& e) {
        cout << e.what();
    }
    catch (const BankException& e) {
        cout << e.what();
    }

    return 0;
}