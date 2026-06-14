#include <iostream>
using namespace std;

class Election {
private:
    int regions, candidates;
    int votes[50][50];

public:
    void input() {
        cout << "Enter Regions and Candidates: ";
        cin >> regions >> candidates;

        for (int i = 0; i < regions; i++) {
            for (int j = 0; j < candidates; j++) {
                cin >> votes[i][j];
            }
        }
    }

    void regionalWinners() {
        for (int i = 0; i < regions; i++) {
            int maxVote = votes[i][0];
            int winner = 0;
            bool tie = false;

            for (int j = 1; j < candidates; j++) {
                if (votes[i][j] > maxVote) {
                    maxVote = votes[i][j];
                    winner = j;
                    tie = false;
                }
                else if (votes[i][j] == maxVote)
                    tie = true;
            }

            if (tie)
                cout << "Region " << i + 1 << ": Tie\n";
            else
                cout << "Region " << i + 1
                     << ": Candidate "
                     << winner + 1 << endl;
        }
    }

    void overallWinner() {
        int total[50] = {0};

        for (int j = 0; j < candidates; j++)
            for (int i = 0; i < regions; i++)
                total[j] += votes[i][j];

        int maxVote = total[0];
        int winner = 0;
        bool tie = false;

        for (int j = 1; j < candidates; j++) {
            if (total[j] > maxVote) {
                maxVote = total[j];
                winner = j;
                tie = false;
            }
            else if (total[j] == maxVote)
                tie = true;
        }

        if (tie)
            cout << "\nOverall Result: Tie\n";
        else
            cout << "\nOverall Winner: Candidate "
                 << winner + 1 << endl;
    }
};

int main() {
    Election e;

    e.input();
    e.regionalWinners();
    e.overallWinner();

    return 0;
}
