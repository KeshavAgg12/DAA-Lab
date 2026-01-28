#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> freq;
    int x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        freq[x]++;
    }

    int ans = 0;

    for (auto it : freq) {
        int start = it.first;
        int count = 0;

        for (int v = start; v <= start + 10; v++) {
            if (freq.find(v) != freq.end()) {
                count += freq[v];
            }
        }
        if (count > ans)
            ans = count;
    }

    cout << ans;
    return 0;
}
