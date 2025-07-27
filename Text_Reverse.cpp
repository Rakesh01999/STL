#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;cin >> T;
    cin.ignore();
    
    while (T--) {
        string line;
        getline(cin, line);
        
        istringstream iss(line); 
        string word;

        bool first = true;
        while (iss >> word) {
            reverse(word.begin(), word.end());
            
            if (!first) cout << " ";
            cout << word;
            first = false;
        }
        cout << '\n'; 
        
    }

    return 0;
}
