#include <iostream>
#include <sstream>  // for istringstream
#include <string>
#include <algorithm> // for reverse()

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); // 🔁 Ignore the newline after the integer input

    while (T--) {
        string line;
        getline(cin, line); // 🔁 Read the whole line with spaces

        istringstream iss(line); // Stream to split line into words
        string word;

        bool first = true;
        while (iss >> word) {
            reverse(word.begin(), word.end()); // 🔁 Reverse the word

            if (!first) cout << " "; // Add space if it's not the first word
            cout << word;
            first = false;
        }
        cout << '\n'; // Newline after each test case
    }

    return 0;
}
