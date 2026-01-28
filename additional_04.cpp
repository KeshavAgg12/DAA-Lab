#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long result = 0;

    for (int i = 0; i < n; i++) {
        int pref[10005] = {0};
        int sum = 0;
        pref[0] = 1;

        bool ok = false;

        for (int j = 0; j < n; j++) {
            if (a[j] > a[i]) sum++;

            if (sum - k >= 0 && pref[sum - k] > 0) {
                ok = true;
                break;
            }
            pref[sum]++;
        }

        if (ok) result += a[i];
    }

    cout << result;
    return 0;
}
