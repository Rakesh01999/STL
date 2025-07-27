#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> left, right;

    for (int i = 0; i < n; i++) {
        int x, a;
        cin >> x >> a;
        if (x < 0) {
            left.push_back({x, a});
        } else {
            right.push_back({x, a});
        }
    }

    // Sort left (from closest to 0, so descending order)
    sort(left.begin(), left.end(), greater<>());
    // Sort right (from closest to 0, so ascending order)
    sort(right.begin(), right.end());

    int total = 0;
    int len = min(left.size(), right.size());

    // Pick equal number from both sides
    for (int i = 0; i < len; i++) {
        total += left[i].second;
        total += right[i].second;
    }

    // Take one extra from the side that has more trees
    if (left.size() > right.size()) {
        total += left[len].second;
    } else if (right.size() > left.size()) {
        total += right[len].second;
    }

    cout << total << endl;

    return 0;
}
