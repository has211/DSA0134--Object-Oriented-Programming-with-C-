#include <iostream>
using namespace std;

class Demo {
    int x;

public:
    // Constructor
    Demo(int a) {
        x = a;
        cout << "Construct ";
    }

    // Copy Constructor
    Demo(const Demo &d) {
        x = d.x;
        cout << "Copy ";
    }

    // Destructor
    ~Demo() {
        cout << "Destruct ";
    }

    // Operator Overloading
    Demo operator+(Demo d) {
        cout << "Add ";
        return Demo(x + d.x);
    }

    void display() {
        cout << "\nValue = " << x << endl;
    }
};

int main() {
    Demo d1(5);
    Demo d2(10);

    Demo d3 = d1 + d2;

    d3.display();

    return 0;
}

Output:
Construct
Construct
Copy
Add
Construct
Destruct
Destruct
Destruct
Destruct

