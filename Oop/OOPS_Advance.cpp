// ============================================================
// File: OOPS_Advance.cpp
// Folder: Oop
// Purpose: Practices advanced OOP concepts like copy constructors and static members.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>
#include <string>

class bankAccount
{
private:
    int accNumber;
    std::string accountName;
    double balance;

    int* transactions;
    int count;

    static int totalAccounts;

public:
    // Constructor
    bankAccount(int accNumber,
                const std::string& accountName,
                double balance);

    // Copy Constructor
    bankAccount(const bankAccount& other);

    // Destructor
    ~bankAccount();

    // Member Functions
    void deposit(int amount);
    void withdraw(int amount);
    void display() const;

    // Static Function
    static void displayTotalAccounts();

    // Operator Overloading
    bool operator==(const bankAccount& other) const;

    // Friend Function
    friend void showBalance(const bankAccount& account);
};

int bankAccount::totalAccounts = 0;

//-----------------------------------------------------

bankAccount::bankAccount(int accNumber,
                         const std::string& accountName,
                         double balance)
    : accNumber(accNumber),
      accountName(accountName),
      balance(balance)
{
    transactions = new int[10];
    count = 0;

    totalAccounts++;
}

//-----------------------------------------------------

bankAccount::bankAccount(const bankAccount& other)
    : accNumber(other.accNumber),
      accountName(other.accountName),
      balance(other.balance),
      count(other.count)
{
    // Allocate new memory for this object
    transactions = new int[10];

    for (int i = 0; i < count; i++)
    {
        transactions[i] = other.transactions[i];
    }

    // A new object has been created
    totalAccounts++;

    std::cout << "Copy Constructor Called\n";
}

//-----------------------------------------------------

bankAccount::~bankAccount()
{
    delete[] transactions;
    transactions = nullptr;

    totalAccounts--;

    std::cout << "Destructor Called\n";
}

//-----------------------------------------------------

void bankAccount::deposit(int amount)
{
    if (count < 10)
    {
        balance += amount;

        transactions[count] = amount;
        count++;

        std::cout << amount << " deposited successfully.\n";
    }
    else
    {
        std::cout << "Transaction history is full.\n";
    }
}

//-----------------------------------------------------

void bankAccount::withdraw(int amount)
{
    if (count < 10)
    {
        balance -= amount;

        transactions[count] = -amount;
        count++;

        std::cout << amount << " withdrawn successfully.\n";
    }
    else
    {
        std::cout << "Transaction history is full.\n";
    }
}

//-----------------------------------------------------

void bankAccount::display() const
{
    std::cout << "\nAccount Number : " << accNumber << '\n';
    std::cout << "Account Name   : " << accountName << '\n';
    std::cout << "Balance        : " << balance << '\n';

    std::cout << "\nTransactions:\n";

    for (int i = 0; i < count; i++)
    {
        std::cout << transactions[i] << '\n';
    }
}

void bankAccount::displayTotalAccounts()
{
    std::cout << "Total Accounts : "
              << totalAccounts
              << '\n';
}
int main()
{
    std::cout << "========== Bank Account Demo ==========\n\n";

    bankAccount account1(101, "Vibhav", 5000);

    account1.deposit(1000);
    account1.deposit(500);
    account1.withdraw(800);

    account1.display();

    std::cout << "\n---------------------------------\n";

    bankAccount account2 = account1;

    bankAccount::displayTotalAccounts();

    return 0;
}