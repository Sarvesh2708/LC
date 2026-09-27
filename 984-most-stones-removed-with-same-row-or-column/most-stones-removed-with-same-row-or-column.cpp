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
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        int n= stones.size();
        for(auto it : stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int,int> stoneNodes;        
        for(auto it : stones){
            int noderow = it[0];
            int nodecol = it[1] + maxRow+1;
            ds.unionBySize(noderow,nodecol);
            stoneNodes[noderow]=1;
            stoneNodes[nodecol]=1;
        }

        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findUparent(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;


    }
};