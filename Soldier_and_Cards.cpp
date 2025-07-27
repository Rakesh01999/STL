#include <iostream>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

int main() {
    int n;cin >> n;

    int k1;cin >> k1;
    queue<int> p1;
    for (int i = 0; i < k1; ++i) {
        int x;
        cin >> x;
        p1.push(x);
    }

    int k2;cin >> k2;
    queue<int> p2;
    for (int i = 0; i < k2; ++i) {
        int x;
        cin >> x;
        p2.push(x);
    }

    int rounds = 0;
    set<pair<queue<int>, queue<int>>> seen;

    while (!p1.empty() && !p2.empty()) {
        if (seen.count({p1, p2})) {
            cout << -1 << endl;
            return 0;
        }
        seen.insert({p1, p2});

        int c1 = p1.front(); p1.pop();
        int c2 = p2.front(); p2.pop();

        if (c1 > c2) {
            p1.push(c2);
            p1.push(c1);
        } else {
            p2.push(c1);
            p2.push(c2);
        }

        rounds++;
    }

    if (p1.empty()) {
        cout << rounds << " 2\n";
    } else {
        cout << rounds << " 1\n";
    }

    return 0;
}
