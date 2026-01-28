#include <iostream>
using namespace std;

int maxPairSum(int arr[], int n) {
    int max1 = arr[0];
    int max2 = arr[1];

    if (max2 > max1) {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }
    return max1 + max2;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxPairSum(arr, n);
    return 0;
}
