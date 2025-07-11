#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    unordered_map<int, long long> freq;
    int x;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        freq[x]++;
    }

    long long total_pairs = n * (n - 1) / 2;

    for (auto it = freq.begin(); it != freq.end(); ++it) {
        long long count = it->second;
        total_pairs -= count * (count - 1) / 2;
    }

    cout << total_pairs << '\n';
    return 0;
}
