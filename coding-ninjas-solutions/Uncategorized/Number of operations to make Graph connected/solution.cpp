#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }

    void unionByrank(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;
        
        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

int makeGraphConnected(int n, vector<pair<int, int>>& edges, int m) {
    DisjointSet ds(n);

    int extraEdges = 0;

    // Step 1: Process all edges and count redundant ones
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        // If both nodes already share the same ultimate parent, this edge is redundant
        if (ds.findUparent(u) == ds.findUparent(v)) {
            extraEdges++;
        } else {
            ds.unionByrank(u, v);
        }
    }

    // Step 2: Count total connected components (nodes 1 to n)
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (ds.findUparent(i) == i) {
            components++;
        }
    }

    // Step 3: Check if we have enough extra edges to join all components
    int requiredEdges = components - 1;

    if (extraEdges >= requiredEdges) {
        return requiredEdges;
    }

    return -1; // Not enough redundant edges to connect everything
}