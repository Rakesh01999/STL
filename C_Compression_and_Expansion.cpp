#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int n;
    cin >> n;
    vector<int> path;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        if (val == 1) {
            path.push_back(1);
        } else {
            // Step up in the path until we find an element such that last + 1 == val
            while (!path.empty() && path.back() + 1 != val) {
                path.pop_back();
            }

            // Replace the last element with val
            if (!path.empty()) {
                path.back() = val;
            }
        }

        // Print the current reconstructed item
        for (size_t j = 0; j < path.size(); ++j) {
            if (j > 0) cout << ".";
            cout << path[j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve_case();
    }

    return 0;
}
