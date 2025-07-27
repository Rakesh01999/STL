#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

int main() {
    int t;
    int scenario = 1;
    
    while (cin >> t && t != 0) {
        cout << "Scenario #" << scenario << endl;
        
        // Map element to team number
        map<int, int> elementToTeam;
        
        // Read team descriptions
        for (int i = 0; i < t; i++) {
            int teamSize;
            cin >> teamSize;
            for (int j = 0; j < teamSize; j++) {
                int element;
                cin >> element;
                elementToTeam[element] = i;
            }
        }
        
        // Main queue to track order of teams
        queue<int> teamOrder;
        
        // Individual queues for each team
        vector<queue<int>> teamQueues(t);
        
        // Track which teams are currently in the main queue
        vector<bool> teamInQueue(t, false);
        
        string command;
        while (cin >> command && command != "STOP") {
            if (command == "ENQUEUE") {
                int x;
                cin >> x;
                
                int team = elementToTeam[x];
                teamQueues[team].push(x);
                
                // If this team is not already in the main queue, add it
                if (!teamInQueue[team]) {
                    teamOrder.push(team);
                    teamInQueue[team] = true;
                }
            }
            else if (command == "DEQUEUE") {
                // Get the team at the front of the main queue
                int frontTeam = teamOrder.front();
                
                // Dequeue from that team's queue
                int element = teamQueues[frontTeam].front();
                teamQueues[frontTeam].pop();
                
                cout << element << endl;
                
                // If this team's queue is now empty, remove it from main queue
                if (teamQueues[frontTeam].empty()) {
                    teamOrder.pop();
                    teamInQueue[frontTeam] = false;
                }
            }
        }
        
        cout << endl;
        scenario++;
    }
    
    return 0;
}