#include <iostream>
using namespace std;

class Team {
private:
    string name;
    int wins, draws, losses;
    int goalsScored, goalsConceded;

public:
    static int totalTeams;

    void input() {
        cin >> name >> wins >> draws >> losses
            >> goalsScored >> goalsConceded;

        totalTeams++;
    }

    int points() {
        return wins * 3 + draws;
    }

    int goalDifference() {
        return goalsScored - goalsConceded;
    }

    string getName() {
        return name;
    }

    void display() {
        cout << name
             << " Points: " << points()
             << " GD: " << goalDifference()
             << endl;
    }
};

int Team::totalTeams = 0;

int main() {
    int n;
    cin >> n;

    Team t[20];

    for (int i = 0; i < n; i++)
        t[i].input();

    int champion = 0;

    for (int i = 0; i < n; i++) {
        t[i].display();

        if (t[i].points() > t[champion].points())
            champion = i;
        else if (t[i].points() == t[champion].points()) {
            if (t[i].goalDifference() >
                t[champion].goalDifference())
                champion = i;
        }
    }

    cout << "\nChampion Team: "
         << t[champion].getName();

    cout << "\nTotal Teams: "
         << Team::totalTeams;

    return 0;
}
