#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, string> dict;
    string line, english, foreign;

    // Read dictionary entries
    while (getline(cin, line) && !line.empty()) {
        size_t spacePos = line.find(' ');
        english = line.substr(0, spacePos);
        foreign = line.substr(spacePos + 1);
        dict[foreign] = english;
    }

    // Read and translate the foreign message
    while (getline(cin, foreign)) {
        if (dict.find(foreign) != dict.end()) {
            cout << dict[foreign] << "\n";
        } else {
            cout << "eh\n";
        }
    }

    return 0;
}
