#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) +
                (a.y - b.y)*(a.y - b.y));
}

void sortX(Point p[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (p[j].x < p[i].x)
                swap(p[i], p[j]);
}

double closest(Point p[], int n) {
    double ans = 1e18;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            ans = min(ans, dist(p[i], p[j]));
    return ans;
}

int main() {
    Point p[16] = {
        {9,3},{2,6},{15,3},{5,1},{1,2},{12,4},{7,2},{4,7},
        {16,5},{3,3},{10,5},{6,4},{14,6},{8,6},{11,1},{13,2}
    };

    sortX(p, 16);
    cout << closest(p, 16);
    return 0;
}
