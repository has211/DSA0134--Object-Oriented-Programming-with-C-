#include <iostream>
using namespace std;

class Box {
    float volume;

public:
    Box(float v) {
        volume = v;
    }

    bool operator>(Box b) {
        return volume > b.volume;
    }
};

int main() {
    Box b1(100), b2(80);

    if(b1 > b2)
        cout << "Box 1 has greater volume";
    else
        cout << "Box 2 has greater volume";
}
