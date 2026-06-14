#include <iostream>
using namespace std;

class Product {
private:
    string productName;
    double price;
    int quantity;

public:
    static int totalProducts;

    void getData() {
        cout<<"Product Name: ";
        cin>>productName;

        cout<<"Price: ";
        cin>>price;

        cout<<"Quantity: ";
        cin>>quantity;

        if(price<=0 || quantity<=0) {
            cout<<"Invalid Input\n";
            price=0;
            quantity=0;
        }

        totalProducts++;
    }

    double calculateTotal() {
        return price * quantity;
    }

    void display() {
        cout<<"\nProduct: "<<productName
            <<"\nPrice: "<<price
            <<"\nQuantity: "<<quantity
            <<"\nCost: "<<calculateTotal()<<endl;
    }
};

int Product::totalProducts=0;

int main() {
    int n;
    double totalBill=0;

    cin>>n;

    Product p[50];

    for(int i=0;i<n;i++)
        p[i].getData();

    for(int i=0;i<n;i++) {
        p[i].display();
        totalBill += p[i].calculateTotal();
    }

    cout<<"\nTotal Products: "
        <<Product::totalProducts;

    cout<<"\nTotal Bill: Rs."
        <<totalBill;
}
