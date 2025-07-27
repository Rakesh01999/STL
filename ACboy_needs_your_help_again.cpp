#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        stack<int> st;
        queue<int> q;
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s == "FILO")
        {
            while (n--)
            {
                string command;
                cin >> command;
                if (command == "IN")
                {
                    int val;
                    cin >> val;
                    st.push(val);
                }
                if (command == "OUT")
                {
                    if (!st.empty())
                    {
                        cout << st.top() << endl;
                        st.pop();
                    }
                    else
                    {
                        cout << "None" << endl;
                    }
                }
            }
        }
        else
        {
            while (n--)
            {
                string command;
                cin >> command;
                if (command == "IN")
                {
                    int val;
                    cin >> val;
                    q.push(val);
                }
                if (command == "OUT")
                {
                    if (!q.empty())
                    {
                        cout << q.front() << endl;
                        q.pop();
                    }
                    else
                    {
                        cout << "None" << endl;
                    }
                }
            }
        }
    }

    return 0;
}