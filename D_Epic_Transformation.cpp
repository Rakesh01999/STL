#include <cstdio>
#include <unordered_map>
#include <algorithm>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        std::unordered_map<int, int> freq;
        freq.reserve(n); 

        int maxFreq = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            freq[x]++;
            if (freq[x] > maxFreq)
                maxFreq = freq[x];
        }

        if (maxFreq > n - maxFreq)
            printf("%d\n", 2 * maxFreq - n);
        else
            printf("%d\n", n % 2);
    }

    return 0;
}
