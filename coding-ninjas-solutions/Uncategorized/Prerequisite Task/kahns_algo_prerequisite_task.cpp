#include <bits/stdc++.h>
using namespace std;

bool prerequisiteTask(vector<vector<int>>& dependency, int n, int m) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    // Build graph
    for (auto &it : dependency) {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        indegree[v]++;
    }

    // Put all nodes with indegree 0 in queue
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Kahn's Algorithm
    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        count++;

        for (int next : adj[node]) {
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // If all tasks are processed, no cycle exists
    return count == n;
}
