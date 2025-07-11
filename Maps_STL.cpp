
#include <bits/stdc++.h>
using namespace std; 

int main() {
    map<string, int> studentMarks; 
    int numQueries;
    cin >> numQueries; 
    for (int i = 0; i < numQueries; ++i) {
        int type;
        cin >> type; 
        
        if (type == 1) {
            string name;
            int marks;
            cin >> name >> marks;
            studentMarks[name] += marks; 
        } else if (type == 2) {
            string name;
            cin >> name; 
            studentMarks.erase(name);
        } else if (type == 3) {
            string name;
            cin >> name; 
            if (studentMarks.count(name)) {
                cout << studentMarks[name] << endl; 
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0; 
}

