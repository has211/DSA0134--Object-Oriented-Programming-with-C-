#include <iostream>
using namespace std;

class Warehouse {
private:
    int itemID, quantity;
    string name, location;

public:
    static int totalItems;

    void addItem() {
        cout<<"Item ID: ";
        cin>>itemID;

        cout<<"Name: ";
        cin>>name;

        cout<<"Quantity: ";
        cin>>quantity;

        cout<<"Location: ";
        cin>>location;

        if(quantity>=0)
            totalItems++;
        else
            quantity=0;
    }

    void updateInventory() {
        int newQty;
        cout<<"New Quantity: ";
        cin>>newQty;

        if(newQty>=0)
            quantity=newQty;
    }

    void display() {
        cout<<"\nItem ID: "<<itemID
            <<"\nName: "<<name
            <<"\nQuantity: "<<quantity
            <<"\nLocation: "<<location<<endl;
    }
};

int Warehouse::totalItems=0;

int main() {
    int n;
    cin>>n;

    Warehouse w[50];

    for(int i=0;i<n;i++)
        w[i].addItem();

    for(int i=0;i<n;i++)
        w[i].display();

    cout<<"\nTotal Items Stored: "
        <<Warehouse::totalItems;
}
