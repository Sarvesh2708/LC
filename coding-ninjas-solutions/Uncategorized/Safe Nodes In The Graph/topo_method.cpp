#include <bits/stdc++.h> 
using namespace std;

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {

    // Reverse adjacency list
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    // Original edge: u -> v
    // Reverse edge: v -> u
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adj[v].push_back(u);
        indegree[u]++;
    }

    queue<int> q;

    // Terminal nodes have outdegree 0
    // In the reversed graph, their indegree is 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> safenode;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        safenode.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    sort(safenode.begin(), safenode.end());

    return safenode;
}
