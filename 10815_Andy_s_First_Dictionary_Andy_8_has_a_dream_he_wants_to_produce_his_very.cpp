#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> dictionary;
    string word;
    string line;

    while (getline(cin, line)) {
        for (char ch : line) {
            if (isalpha(ch)) {
                word += tolower(ch);
            } else {
                if (!word.empty()) {
                    dictionary.insert(word);
                    word.clear();
                }
            }
        }
        // In case the line ends with a word
        if (!word.empty()) {
            dictionary.insert(word);
            word.clear();
        }
    }

    for (const string& w : dictionary) {
        cout << w << '\n';
    }

    return 0;
}
