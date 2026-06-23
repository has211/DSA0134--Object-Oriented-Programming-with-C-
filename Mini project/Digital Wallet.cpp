#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
// Base Class
class Transaction
{
protected:
    double amount;
    string category;
    string date;
public:
    Transaction(double amt, string cat, string dt)
    {
        amount = amt;
        category = cat;
        date = dt;
    }
    virtual void display() = 0;
    double getAmount()
    {
        return amount;
    }
    string getCategory()
    {
        return category;
    }
    string getDate()
    {
        return date;
    }
    virtual string getType() = 0;
    virtual ~Transaction() {}
};

// Derived Class - Income
class Income : public Transaction
{
public:
    Income(double amt, string dt)
        : Transaction(amt, "Income", dt) {}

    void display()
    {
        cout << "Income  | Rs." << amount
             << " | Date: " << date << endl;
    }
    string getType()
    {
        return "Income";
    }
};

// Derived Class - Expense
class Expense : public Transaction
{
public:
    Expense(double amt, string cat, string dt)
        : Transaction(amt, cat, dt) {}
    void display()
    {
        cout << "Expense | Rs." << amount
             << " | Category: " << category
             << " | Date: " << date << endl;
    }
    string getType()
    {
        return "Expense";
    }
};
// User Class
class User
{
private:
    string username;
    string password;
public:
    User()
    {
        username = "admin";
        password = "admin123";
    }
    bool login()
    {
        string u, p;
        cout << "\nUsername: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;
        if (u == username && p == password)
        {
            cout << "\nLogin Successful!\n";
            return true;
        }
        cout << "\nInvalid Login!\n";
        return false;
    }
};
// Wallet Class
class Wallet
{
private:
    double balance;
    vector<Transaction *> transactions;

public:
    Wallet()
    {
        balance = 0;
    }
    void addMoney()
    {
        double amt;
        string date;
        cout << "Enter Amount: ";
        cin >> amt;
        cout << "Enter Date(dd-mm-yyyy): ";
        cin >> date;
        balance += amt;
        transactions.push_back(
            new Income(amt, date));
        cout << "Money Added Successfully!\n";
    }
    void spendMoney()
    {
        double amt;
        string category, date;
        cout << "Enter Amount: ";
        cin >> amt;
        if (amt > balance)
        {
            cout << "Insufficient Balance!\n";
            return;
        }
        cout << "Enter Category: ";
        cin >> category;
        cout << "Enter Date(dd-mm-yyyy): ";
        cin >> date;
        balance -= amt;
        transactions.push_back(
            new Expense(amt, category, date));

        cout << "Expense Recorded!\n";
    }
    void showBalance()
    {
        cout << "\nCurrent Balance = Rs."
             << balance << endl;
    }
    void showTransactions()
    {
        if (transactions.empty())
        {
            cout << "\nNo Transactions Found!\n";
            return;
        }
        cout << "\n----- TRANSACTION HISTORY -----\n";

        for (int i = 0; i < transactions.size(); i++)
        {
            transactions[i]->display();
        }
    }
    void expenseSummary()
    {
        double totalExpense = 0;

        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i]->getType() == "Expense")
            {
                totalExpense += transactions[i]->getAmount();
            }
        }
        cout << "\nTotal Expense = Rs."
             << totalExpense << endl;
    }
    void searchCategory()
    {
        string cat;
        cout << "Enter Category: ";
        cin >> cat;
        cout << "\nMatching Transactions\n";
        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i]->getCategory() == cat)
            {
                transactions[i]->display();
            }
        }
    }
    void monthlyReport()
    {
        string month;
        cout << "Enter Month and Year (mm-yyyy): ";
        cin >> month;
        double total = 0;
        cout << "\nMonthly Transactions\n";
        for (int i = 0; i < transactions.size(); i++)
        {
            string date = transactions[i]->getDate();
            if (date.substr(3, 7) == month)
            {
                transactions[i]->display();
                if (transactions[i]->getType() == "Expense")
                    total += transactions[i]->getAmount();
            }
        }
        cout << "\nTotal Expense = Rs."
             << total << endl;
    }
    void saveToFile()
    {
        ofstream fout("transactions.txt");
        fout << balance << endl;
        for (int i = 0; i < transactions.size(); i++)
        {
            fout << transactions[i]->getType() << " "
                 << transactions[i]->getAmount() << " "
                 << transactions[i]->getCategory() << " "
                 << transactions[i]->getDate()
                 << endl;
        }
        fout.close();
        cout << "Data Saved Successfully!\n";
    }
    void loadFromFile()
    {
        ifstream fin("transactions.txt");
        if (!fin)
        {
            cout << "No Previous Data Found!\n";
            return;
        }
        balance = 0;
        string type, category, date;
        double amount;
        fin >> balance;
        while (fin >> type >> amount >> category >> date)
        {
            if (type == "Income")
                transactions.push_back(
                    new Income(amount, date));
            else
                transactions.push_back(
                    new Expense(amount, category, date));
        }
        fin.close();

        cout << "Data Loaded Successfully!\n";
    }
    ~Wallet()
    {
        for (int i = 0; i < transactions.size(); i++)
        {
            delete transactions[i];
        }
    }
};
// Main Function
int main()
{
    User user;
    Wallet wallet;
    if (!user.login())
        return 0;
    int choice;
    do
    {
        cout << "\n\n===== DIGITAL WALLET =====\n";
        cout << "1. Add Money\n";
        cout << "2. Spend Money\n";
        cout << "3. View Balance\n";
        cout << "4. View Transactions\n";
        cout << "5. Expense Summary\n";
        cout << "6. Search Category\n";
        cout << "7. Monthly Report\n";
        cout << "8. Save Data\n";
        cout << "9. Load Data\n";
        cout << "10. Exit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            wallet.addMoney();
            break;
        case 2:
            wallet.spendMoney();
            break;
        case 3:
            wallet.showBalance();
            break;
        case 4:
            wallet.showTransactions();
            break;
        case 5:
            wallet.expenseSummary();
            break;
        case 6:
            wallet.searchCategory();
            break;
        case 7:
            wallet.monthlyReport();
            break;
        case 8:
            wallet.saveToFile();
            break;
        case 9:
            wallet.loadFromFile();
            break;
        case 10:
            cout << "Thank You!\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }
    } while (choice != 10);
    return 0;
}
