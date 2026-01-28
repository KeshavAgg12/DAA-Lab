#include <iostream>
using namespace std;

bool canDivide(int A[], int N, int M, int maxOR) {
    int segments = 1;
    int currentOR = 0;

    for (int i = 0; i < N; i++) {
        if ((currentOR | A[i]) <= maxOR) {
            currentOR = currentOR | A[i];
        } else {
            segments++;
            currentOR = A[i];
        }
    }
    return segments <= M;
}

int minimizeMaxOR(int A[], int N, int M) {
    int low = 0, high = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] > low)
            low = A[i];
        high = high | A[i];
    }

    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canDivide(A, N, M, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main() {
    int N, M;
    cin >> N >> M;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << minimizeMaxOR(A, N, M);
    return 0;
}
