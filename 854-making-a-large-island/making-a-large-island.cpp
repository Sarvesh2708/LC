#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUparent(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUparent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ultp_u = findUparent(u);
        int ultp_v = findUparent(v);

        if(ultp_u == ultp_v)
            return;

        if(size[ultp_u] < size[ultp_v]) {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }

    int getsize(int node) {
        return size[findUparent(node)];
    }
};






class Solution {

private:
bool isvalid(int nrow, int ncol, int n) {
    return nrow >= 0 && nrow < n &&
           ncol >= 0 && ncol < n;
}

public:
    int largestIsland(vector<vector<int>>& grid) {
      int n = grid.size();

    DisjointSet ds(n * n);

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // Step 1: Connect all adjacent 1s
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {

            if(grid[row][col] == 0)
                continue;

            int node = row * n + col;

            for(int idx = 0; idx < 4; idx++) {

                int nrow = row + drow[idx];
                int ncol = col + dcol[idx];

                if(isvalid(nrow, ncol, n) &&
                   grid[nrow][ncol] == 1) {

                    int adjNode = nrow * n + ncol;

                    ds.unionBySize(node, adjNode);
                }
            }
        }
    }

    // Step 2: Find largest existing island
    int ans = 0;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {

            if(grid[row][col] == 1) {
                ans = max(ans, ds.getsize(row * n + col));
            }
        }
    }

    // Step 3: Convert one 0 into 1
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {

            if(grid[row][col] == 1)
                continue;

            set<int> components;

            for(int k = 0; k < 4; k++) {

                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if(isvalid(nrow, ncol, n) &&
                   grid[nrow][ncol] == 1) {

                    int adjNode = nrow * n + ncol;

                    components.insert(
                        ds.findUparent(adjNode)
                    );
                }
            }

            int totalSize = 1;

            for(auto component : components) {
                totalSize += ds.getsize(component);
            }

            ans = max(ans, totalSize);
        }
    }

    return ans;
}
};