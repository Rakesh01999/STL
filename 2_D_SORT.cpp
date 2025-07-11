
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Point {
    long long x, y;
};

bool comparePoints(const Point& a, const Point& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y > b.y;
}

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld %lld", &points[i].x, &points[i].y);
        }

        sort(points.begin(), points.end(), comparePoints);

        for (int i = 0; i < n; ++i) {
            printf("%lld %lld\n", points[i].x, points[i].y);
        }
    }

    return 0;
}

