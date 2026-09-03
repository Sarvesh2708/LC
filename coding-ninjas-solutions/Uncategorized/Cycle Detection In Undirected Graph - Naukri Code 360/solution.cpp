#include <bits/stdc++.h>
using namespace std;


string cycleDetection(vector<vector<int>>& edges, int n, int m)
{
    // Build an adjacency list
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create a visited array
    vector<int> visited(n + 1, 0);

    // Check all components
    for (int start = 1; start <= n; start++)
    {
        if (visited[start])
            continue;

        queue<pair<int, int>> q;

        q.push({start, -1});
        visited[start] = 1;

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();  // <-- You were missing this

            for (auto neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = 1;
                    q.push({neighbor, node});
                }
                else if (neighbor != parent)
                {
                    return "Yes";
                }
            }
        }
    }

    return "No";
}
