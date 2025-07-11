
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<pair<int, int>, string> codeWordMap;

    int n;
    cin >> n; 
    
    for (int i = 0; i < n; ++i) {
        int code1, code2;
        string girlName;
        cin >> code1 >> code2 >> girlName;
        codeWordMap[{code1, code2}] = girlName; 
    }

    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int code1, code2;
        cin >> code1 >> code2;
        cout << codeWordMap[{code1, code2}] << "\n"; 
    }

    return 0;
}

