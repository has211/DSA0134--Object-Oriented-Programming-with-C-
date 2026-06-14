#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char *name;
    int marks;

public:
    Student(const char *n, int m) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        marks = m;
    }

    Student(const Student &s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        marks = s.marks;
    }

    void setName(const char *n) {
        strcpy(name, n);
    }

    void display() {
        cout << "Name: " << name << " Marks: " << marks << endl;
    }

    ~Student() {
        delete[] name;
    }
};

int main() {
    Student s1("Hasini", 90);
    Student s2 = s1;

    s2.setName("Govind");

    s1.display();
    s2.display();

    return 0;
}
