#include <bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int>& arrival, vector<int>& departure) {
    int n = arrival.size();

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platformsNeeded = 0;
    int maxPlatforms = 0;

    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platformsNeeded++;
            maxPlatforms = max(maxPlatforms, platformsNeeded);
            i++;
        } 
        else {
            platformsNeeded--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {
    vector<int> arrival  = {900, 910, 920, 1100, 1120};
    vector<int> departure = {940, 1200, 950, 1130, 1140};

    cout << "Minimum Platforms Required = "
         << minPlatforms(arrival, departure);

    return 0;
}
