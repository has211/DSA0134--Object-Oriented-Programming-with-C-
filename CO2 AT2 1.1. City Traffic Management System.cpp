#include <iostream>
#include <string>
using namespace std;

class Violation {
private:
    string vehicleNo, ownerName, violationType;
    double fineAmount;

public:
    static int totalViolations;

    void getData() {
        cout << "Vehicle Number: ";
        cin >> vehicleNo;

        cout << "Owner Name: ";
        cin.ignore();
        getline(cin, ownerName);

        cout << "Violation Type (Signal/Parking/Speed): ";
        cin >> violationType;

        calculateFine();
    }

    bool validateVehicle() {
        return vehicleNo.length() >= 6;
    }

    void calculateFine() {
        if (violationType == "Signal")
            fineAmount = 500;
        else if (violationType == "Parking")
            fineAmount = 300;
        else if (violationType == "Speed")
            fineAmount = 1000;
        else {
            cout << "Invalid Violation Type\n";
            fineAmount = 0;
        }

        totalViolations++;
    }

    void display() {
        cout << "\nVehicle No: " << vehicleNo
             << "\nOwner Name: " << ownerName
             << "\nViolation: " << violationType
             << "\nFine Amount: Rs." << fineAmount << endl;
    }
};

int Violation::totalViolations = 0;

int main() {
    int n;
    cout << "Enter number of violations: ";
    cin >> n;

    Violation v[50];

    for(int i=0;i<n;i++)
        v[i].getData();

    for(int i=0;i<n;i++)
        v[i].display();

    cout << "\nTotal Violations: "
         << Violation::totalViolations;
}
