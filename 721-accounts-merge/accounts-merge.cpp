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

    void unionByRank(int u, int v) {
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

class Solution {
public:
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts
    ) {
        int n = accounts.size();

        // Create DSU
        DisjointSet ds(n);

        // email -> account index
        unordered_map<string, int> mpp;

        // Connect accounts having common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mpp.find(mail) == mpp.end()) {
                    mpp[mail] = i;
                }
                else {
                    ds.unionByRank(i, mpp[mail]);
                }
            }
        }

        // Store emails according to their ultimate parent
        vector<vector<string>> mergedMail(n);

        for (auto it : mpp) {
            string mail = it.first;
            int node = ds.findUparent(it.second);

            mergedMail[node].push_back(mail);
        }

        // Construct answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedMail[i].empty())
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            // Account name
            temp.push_back(accounts[i][0]);

            // Emails
            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
