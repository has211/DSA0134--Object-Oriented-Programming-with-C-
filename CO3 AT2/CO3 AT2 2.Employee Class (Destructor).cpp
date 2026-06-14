#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    char *name;
    double salary;

public:
    Employee(const char *n, double s) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        salary = s;
        cout << "Constructor Called\n";
    }

    void display() {
        cout << name << " " << salary << endl;
    }

    ~Employee() {
        delete[] name;
        cout << "Destructor Called\n";
    }
};

int main() {
    Employee e("John", 50000);
    e.display();
}
