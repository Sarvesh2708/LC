#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;

    // initialize the parent and rank arr

    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
    }

    // find ulti parent 
    int findUparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }

    void unionByrank(int u,int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]>rank[ulp_v]) parent[ulp_v]=ulp_u;
        else if(rank[ulp_u]<rank[ulp_v]) parent[ulp_u]=ulp_v;
        else{
            // if both have same rank
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};



int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.
        vector<vector<int>> adjls(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(roads[i][j]==1 && i!=j){
                adjls[i].push_back(j);
            }
        }


        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adjls[i][j]==1){
                    ds.unionByrank(i,j);

                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUparent(i)=i){
                cnt++
            }
        }
        return cnt;
}





















// void dfs(int node,vector<vector<int>> &adjls,vector<int>& vis){
//     vis[node]=1;
//     for(auto it : adjls[node])
//         if(!vis[it]){
//             dfs(it, adjls, vis);
//         }
//     }





// int findNumOfProvinces(vector<vector<int>>& roads, int n) {
//     // Write your code here.
//     // convert adj matrix to adj list;
//     vector<vector<int>> adjls(n);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(roads[i][j]==1 && i!=j){
//                 adjls[i].push_back(j);
//             }
//         }
//     }

//     // create a visited arrary 
//     vector<int> vis(n, 0);
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             cnt++;
//             dfs(i,adjls,vis);
//         }
//     }
//     return cnt;
// }