#include <iostream>
using namespace std;

class Member {
private:
    int memberID;
    string name, planType;
    double fee;

public:
    static int totalMembers;

    void getData() {
        cout << "Member ID: ";
        cin >> memberID;

        cout << "Name: ";
        cin >> name;

        cout << "Plan Type (Basic/Premium/VIP): ";
        cin >> planType;

        calculateFee();
        totalMembers++;
    }

    void calculateFee() {
        if(planType=="Basic")
            fee=1000;
        else if(planType=="Premium")
            fee=2000;
        else if(planType=="VIP")
            fee=3000;
        else {
            cout<<"Invalid Plan\n";
            fee=0;
        }
    }

    void display() {
        cout<<"\nID: "<<memberID
            <<"\nName: "<<name
            <<"\nPlan: "<<planType
            <<"\nFee: "<<fee<<endl;
    }
};

int Member::totalMembers=0;

int main() {
    int n;
    cin>>n;

    Member m[50];

    for(int i=0;i<n;i++)
        m[i].getData();

    for(int i=0;i<n;i++)
        m[i].display();

    cout<<"\nTotal Active Members: "
        <<Member::totalMembers;
}
