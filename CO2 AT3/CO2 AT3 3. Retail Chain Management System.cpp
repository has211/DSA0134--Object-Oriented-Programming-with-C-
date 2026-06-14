#include <iostream>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    void input() {
        cin >> name >> price >> quantity;
    }

    double sales() {
        return price * quantity;
    }

    string getName() {
        return name;
    }
};

class Store {
private:
    Product products[50];
    int n;

public:
    static double overallSales;

    void input() {
        cout << "Enter number of products: ";
        cin >> n;

        for (int i = 0; i < n; i++)
            products[i].input();
    }

    double calculateStoreSales() {
        double total = 0;

        for (int i = 0; i < n; i++)
            total += products[i].sales();

        overallSales += total;

        return total;
    }
};

double Store::overallSales = 0;

int main() {
    int stores;
    cin >> stores;

    Store s[20];

    for (int i = 0; i < stores; i++)
        s[i].input();

    double best = 0;
    int bestStore = 0;

    for (int i = 0; i < stores; i++) {
        double sales = s[i].calculateStoreSales();

        cout << "Store " << i + 1
             << " Sales = "
             << sales << endl;

        if (sales > best) {
            best = sales;
            bestStore = i;
        }
    }

    cout << "\nOverall Sales = "
         << Store::overallSales;

    cout << "\nBest Performing Store = "
         << bestStore + 1;

    return 0;
}
