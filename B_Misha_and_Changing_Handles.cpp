#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    map<string, string> current_to_original;
    
    for (int i = 0; i < q; i++) {
        string old_handle, new_handle;
        cin >> old_handle >> new_handle;
        
        string original;
        if (current_to_original.find(old_handle) != current_to_original.end()) {
            original = current_to_original[old_handle];
            current_to_original.erase(old_handle);
        } else {
            original = old_handle;
        }
        
        current_to_original[new_handle] = original;
    }
    
    int count = 0;
    for (auto& pair : current_to_original) {
        if (pair.first != pair.second) {
            count++;
        }
    }
    
    cout << count << endl;
    
    for (auto& pair : current_to_original) {
        if (pair.first != pair.second) {
            cout << pair.second << " " << pair.first << endl;
        }
    }
    
    return 0;
}