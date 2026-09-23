#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUparent(parent[node]);
    }

    void unionByrank(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    // edges[i] = {u, v, weight}
    // Convert to {weight, u, v} for easy sorting.
    vector<tuple<int, int, int>> edgeList;

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        edgeList.push_back({wt, u, v});
    }

    // Sort edges according to weight
    sort(edgeList.begin(), edgeList.end());

    DisjointSet ds(n);

    int mstWeight = 0;
    int edgesUsed = 0;

    for (auto &[wt, u, v] : edgeList) {

        // If u and v are in different components,
        // adding this edge will not create a cycle.
        if (ds.findUparent(u) != ds.findUparent(v)) {

            mstWeight += wt;
            ds.unionByrank(u, v);
            edgesUsed++;

            // MST of n vertices always has n-1 edges
            if (edgesUsed == n - 1)
                break;
        }
    }

    return mstWeight;
}
