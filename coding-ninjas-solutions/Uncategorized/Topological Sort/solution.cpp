#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> indegree(v,0);
    vector<vector <int>> adj(v);
    queue<int> q;
    for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    
    for(int i=0;i<v;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);


        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }


        }


    }
    return topo;
    
}