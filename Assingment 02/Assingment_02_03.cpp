#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int N = 5;

    vector<Job> jobs = {
        {"J1", 2, 100},
        {"J2", 1, 19},
        {"J3", 2, 27},
        {"J4", 1, 25},
        {"J5", 3, 15}
    };

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (int i = 0; i < N; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    vector<string> slot(maxDeadline + 1, "");

    int totalProfit = 0;
    int jobCount = 0;

    for (int i = 0; i < N; i++) {
        for (int t = jobs[i].deadline; t >= 1; t--) {
            if (slot[t] == "") {
                slot[t] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != "")
            cout << slot[i] << " ";
    }

    cout << endl;
    cout << "Number of Jobs: " << jobCount << endl;
    cout << "Maximum Profit: " << totalProfit << endl;

    return 0;
}
