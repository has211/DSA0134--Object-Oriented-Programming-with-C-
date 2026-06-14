#include <iostream>
using namespace std;

class Distance {
    int meter, cm;

public:
    Distance(int m, int c) {
        meter = m;
        cm = c;
    }

    Distance operator+(Distance d) {
        Distance temp(0,0);
        temp.meter = meter + d.meter;
        temp.cm = cm + d.cm;

        if(temp.cm >= 100) {
            temp.meter++;
            temp.cm -= 100;
        }

        return temp;
    }

    void display() {
        cout << meter << " m " << cm << " cm\n";
    }
};

int main() {
    Distance d1(5,50), d2(4,70);
    Distance d3 = d1 + d2;
    d3.display();
}
