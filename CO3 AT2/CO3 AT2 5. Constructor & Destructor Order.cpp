#include <iostream>
using namespace std;

class Test {
public:
    Test() {
        cout << "Constructor\n";
    }

    ~Test() {
        cout << "Destructor\n";
    }
};

int main() {
    Test t1;

    {
        Test t2;
        {
            Test t3;
        }
    }

    return 0;
}
