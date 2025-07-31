#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    string name;
    int birthYear;
};

// Comparator to sort from youngest to oldest (larger birthYear first)
bool compare(Person a, Person b) {
    return a.birthYear > b.birthYear;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Person> people(n);

        // Read input
        for (int i = 0; i < n; ++i) {
            cin >> ws; // consume any leading whitespaces
            getline(cin, people[i].name, ' ');
            cin >> people[i].birthYear;
        }

        // Sort from youngest to oldest
        sort(people.begin(), people.end(), compare);

        // Output names only
        for (int i = 0; i < n; ++i) {
            cout << people[i].name << endl;
        }
    }

    return 0;
}
