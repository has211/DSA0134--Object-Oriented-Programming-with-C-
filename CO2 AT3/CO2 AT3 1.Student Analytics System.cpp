#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
    void input() {
        cin >> name >> marks;
    }

    int getMarks() {
        return marks;
    }

    string getName() {
        return name;
    }
};

class Department {
private:
    Student students[100];
    int n;

public:
    void input() {
        cout << "Enter number of students: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Student " << i + 1 << " Name and Marks: ";
            students[i].input();
        }
    }

    int topperMarks() {
        if (n == 0) return -1;

        int maxMarks = students[0].getMarks();

        for (int i = 1; i < n; i++)
            if (students[i].getMarks() > maxMarks)
                maxMarks = students[i].getMarks();

        return maxMarks;
    }

    string topperName() {
        if (n == 0) return "No Students";

        int index = 0;

        for (int i = 1; i < n; i++)
            if (students[i].getMarks() > students[index].getMarks())
                index = i;

        return students[index].getName();
    }

    double passPercentage() {
        if (n == 0) return 0;

        int pass = 0;

        for (int i = 0; i < n; i++)
            if (students[i].getMarks() >= 40)
                pass++;

        return (double)pass * 100 / n;
    }
};

int main() {
    int d;
    cout << "Enter number of departments: ";
    cin >> d;

    Department dept[20];

    for (int i = 0; i < d; i++) {
        cout << "\nDepartment " << i + 1 << endl;
        dept[i].input();
    }

    int overallTop = -1;
    string overallName;

    cout << "\nDepartment Results\n";

    for (int i = 0; i < d; i++) {
        cout << "\nDepartment " << i + 1 << endl;
        cout << "Topper: " << dept[i].topperName() << endl;
        cout << "Marks: " << dept[i].topperMarks() << endl;
        cout << "Pass %: " << dept[i].passPercentage() << endl;

        if (dept[i].topperMarks() > overallTop) {
            overallTop = dept[i].topperMarks();
            overallName = dept[i].topperName();
        }
    }

    cout << "\nOverall University Topper: "
         << overallName
         << " (" << overallTop << ")\n";

    return 0;
}
