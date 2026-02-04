#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity arr[n];

    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }

    sort(arr, arr + n, compare);

    int count = 1;
    int lastFinish = arr[0].finish;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastFinish) {
            count++;
            lastFinish = arr[i].finish;
        }
    }

    cout << "Maximum number of activities: " << count;
    return 0;
}
