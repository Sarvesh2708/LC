#include <queue>
#include <vector>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);
    queue<int> q;

    // Create adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
    }

    // Calculate indegree of every node
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;

    // Kahn's Algorithm
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cnt++;

        for (auto it : adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If all nodes are processed, there is no cycle
    if (cnt == n)
        return false;

    // Otherwise, cycle exists
    return true;
}
