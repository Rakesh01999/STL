#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unordered_map<int, int> freqMap;
    vector<int> order;       
    
    int num;
    while (cin >> num) { 
        if (freqMap.count(num) == 0) {
            order.push_back(num);
        }
        freqMap[num]++;
    }

    for (int val : order) {
        cout << val << " " << freqMap[val] << "\n";
    }

    return 0;
}
