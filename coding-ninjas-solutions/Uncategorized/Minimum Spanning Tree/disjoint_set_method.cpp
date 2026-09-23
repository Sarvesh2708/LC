#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUparent(parent[node]);
    }

    void unionByrank(int u, int v) {
        int pu = findUparent(u);
        int pv = findUparent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

struct Edge {
    int u;
    int v;
    int wt;
};

bool compareEdge(Edge a, Edge b) {
    return a.wt < b.wt;
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<Edge> edgeList;
    edgeList.reserve(edges.size());

    for (int i = 0; i < edges.size(); i++) {
        Edge e;
        e.u = edges[i][0];
        e.v = edges[i][1];
        e.wt = edges[i][2];

        edgeList.push_back(e);
    }

    sort(edgeList.begin(), edgeList.end(), compareEdge);

    DisjointSet ds(n);

    int mstWeight = 0;
    int count = 0;

    for (int i = 0; i < edgeList.size(); i++) {
        int u = edgeList[i].u;
        int v = edgeList[i].v;
        int wt = edgeList[i].wt;

        if (ds.findUparent(u) != ds.findUparent(v)) {
            mstWeight += wt;
            ds.unionByrank(u, v);
            count++;

            if (count == n - 1)
                break;
        }
    }

    return mstWeight;
}
