#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    // Adjacency list:
    // adj[u] = {v, weight}
    vector<vector<pair<int, int>>> adj(vertices);

    for (auto &edge : vec) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        // Undirected graph
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // dist[i] = shortest distance from source to i
    vector<int> dist(vertices, INT_MAX);

    // {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Source distance is 0
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Ignore stale entry
        if (dis > dist[node])
            continue;

        // Traverse all neighbours
        for (auto &it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            // Relaxation
            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;

                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}
