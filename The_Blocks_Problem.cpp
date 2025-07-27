#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

const int MAX = 25;

vector<vector<int>> blocks(MAX);
int position[MAX]; // position[i] = stack index where block i currently is

// Return blocks stacked above 'block' to their original positions
void returnAbove(int block) {
    int pos = position[block];
    while (blocks[pos].back() != block) {
        int top = blocks[pos].back();
        blocks[pos].pop_back();
        blocks[top].push_back(top);
        position[top] = top;
    }
}

// Move block a onto block b (after returning blocks above both a and b)
void moveOnto(int a, int b) {
    returnAbove(a);
    returnAbove(b);
    blocks[position[a]].pop_back();
    blocks[position[b]].push_back(a);
    position[a] = position[b];
}

// Move block a over block b (return blocks above a, then place on top of b's stack)
void moveOver(int a, int b) {
    returnAbove(a);
    blocks[position[a]].pop_back();
    blocks[position[b]].push_back(a);
    position[a] = position[b];
}

// Pile blocks starting from a onto block b (return blocks above b first)
void pileOnto(int a, int b);

// Pile blocks starting from a over block b
void pileOver(int a, int b) {
    int from = position[a], to = position[b];
    vector<int> &src = blocks[from];
    vector<int> &dest = blocks[to];
    
    auto it = find(src.begin(), src.end(), a);
    vector<int> moving(it, src.end());
    src.erase(it, src.end());

    for (int block : moving) {
        dest.push_back(block);
        position[block] = to;
    }
}

void pileOnto(int a, int b) {
    returnAbove(b);
    pileOver(a, b);
}

int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line); // consume newline after n

    // Initialize each block in its own position
    for (int i = 0; i < n; ++i) {
        blocks[i].clear();
        blocks[i].push_back(i);
        position[i] = i;
    }

    while (getline(cin, line)) {
        if (line == "quit") break;

        stringstream ss(line);
        string cmd1, cmd2;
        int a, b;
        ss >> cmd1 >> a >> cmd2 >> b;

        if (a == b || position[a] == position[b]) continue;

        if (cmd1 == "move" && cmd2 == "onto") moveOnto(a, b);
        else if (cmd1 == "move" && cmd2 == "over") moveOver(a, b);
        else if (cmd1 == "pile" && cmd2 == "onto") pileOnto(a, b);
        else if (cmd1 == "pile" && cmd2 == "over") pileOver(a, b);
    }

    // Print final state
    for (int i = 0; i < n; ++i) {
        cout << i << ":";
        for (int b : blocks[i]) {
            cout << " " << b;
        }
        cout << "\n";
    }

    return 0;
}
