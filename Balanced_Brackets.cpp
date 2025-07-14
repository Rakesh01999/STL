#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string& s) {
    vector<char> stack; // using vector as a stack

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push_back(c); // push to back
        } else {
            if (stack.empty()) return false;
            char top = stack.back(); // top element
            stack.pop_back(); // remove top
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty(); // if not empty, there are unmatched opening brackets
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout<<isBalanced(s)<<endl;
        cout << (isBalanced(s) ? "YES" : "NO") << '\n';
    }
    return 0;
}
