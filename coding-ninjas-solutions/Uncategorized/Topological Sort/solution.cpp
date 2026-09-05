#include <bits/stdc++.h> 

void dfs(int node,vector<int> &visited,stack<int> &st,vector<vector <int>> &adj){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[node]) dfs(it,visited,st,adj);
    }
    st.push(node);
}



vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    stack<int> st;
    vector<int> visited(v,0);
    vector<vector <int>> adj(v);
    vector<int> ans;
    for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,st,adj);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
return ans;
    
}