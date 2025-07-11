#include <bits/stdc++.h>
using namespace std;

void printMaxInSubarrays(const vector<int> &arr, int k)
{
    deque<int> dq;
    int n = arr.size();

    for (int i = 0; i < n; ++i)
    {
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k - 1)
        {
            cout << arr[dq.front()] << " ";
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        printMaxInSubarrays(arr, k);
    }

    return 0;
}

