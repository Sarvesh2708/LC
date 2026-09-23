#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);          // 0-based indexing: size n
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;          // Initialize 0 to n-1
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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extraEdges = 0;

        // Step 1: Process all connections and count redundant ones
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if (ds.findUparent(u) == ds.findUparent(v)) {
                extraEdges++;
            } else {
                ds.unionByrank(u, v);
            }
        }

        // Step 2: Count connected components from node 0 to n-1
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUparent(i) == i) {
                components++;
            }
        }

        // Step 3: Check if we have enough extra edges to connect all components
        int requiredEdges = components - 1;

        if (extraEdges >= requiredEdges) {
            return requiredEdges;
        }

        return -1;
    }
};