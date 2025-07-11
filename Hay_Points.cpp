
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    unordered_map<string, int> hayDict;
    char word[21];
    int value;

    for (int i = 0; i < m; ++i) {
        scanf("%s %d", word, &value);
        hayDict[string(word)] = value;
    }

    cin.ignore();

    string line;
    int total = 0;
    while (n--) {
        total = 0;
        while (getline(cin, line)) {
            if (line == ".") break;

            stringstream ss(line);
            string token;
            while (ss >> token) {
                if (hayDict.count(token)) {
                    total += hayDict[token];
                }
            }
        }
        printf("%d\n", total);
    }

    return 0;
}
