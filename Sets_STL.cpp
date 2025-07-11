
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    int queries;
    cin >> queries;

    for (int i = 0; i < queries; ++i) {
        int type, value;
        cin >> type >> value;

        if (type == 1) {
            s.insert(value);
        } else if (type == 2) {
            s.erase(value);
        } else if (type == 3) {
            if (s.count(value)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

