#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> freq;
    vector<int> masks(n);
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int mask = 0;
        for (char c : s) {
            mask ^= (1 << (c - 'a')); // Toggle the bit for character c
        }
        masks[i] = mask;
        freq[mask]++;
    }

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        int current_mask = masks[i];
        freq[current_mask]--; // Avoid double counting

        // 1. Pair with exact same mask (even char counts)
        result += freq[current_mask];

        // 2. Pair with masks that differ by one bit (one odd char allowed)
        for (int bit = 0; bit < 26; ++bit) {
            int flipped = current_mask ^ (1 << bit);
            result += freq[flipped];
        }
    }

    cout << result << '\n';
    return 0;
}
