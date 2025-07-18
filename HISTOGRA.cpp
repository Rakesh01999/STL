#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll largestRectangle(vector<ll>& heights) {
    stack<int> st;
    ll maxArea = 0;
    int n = heights.size();
    
    // how , what 
    for (int i = 0; i <= n; ++i) {
        ll h = (i == n ? 0 : heights[i]);
        while (!st.empty() && heights[st.top()] > h) {
            ll height = heights[st.top()];
            st.pop();
            ll width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    
    return maxArea;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<ll> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        cout << largestRectangle(heights) << "\n";
    }

    return 0;
}
