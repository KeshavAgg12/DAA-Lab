#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, H, W;
        cin >> N >> H >> W;

        long long area = N * H * W;
        long long side = ceil(sqrt((long double)area));

        if (side < H) side = H;
        if (side < W) side = W;

        cout << side << "\n";
    }
    return 0;
}
