#include <bits/stdc++.h> 


bool dfs(int node,vector<vector<int>> &adj,vector<int> &visited,vector<int> &pathvisited
,vector<int> &checkmark){
    visited[node]=1;
    pathvisited[node]=1;
    checkmark[node]=0;
    for(auto it: adj[node]){
        if(!visited[it]){
            if(dfs(it,adj,visited,pathvisited,checkmark)){
            checkmark[node]=0; 
            return true;
            }
        }
        else if(!pathvisited[it]){
            checkmark[node]=0;
            return true;
        }
    }
    checkmark[node]=1;
    pathvisited[node]=0;
    return false;
}



vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    // Write your code here.
    vector<vector<int>> adj(n + 1);
    for (auto edge : edges) {
      int u = edge.first;
      int v = edge.second;

      adj[u].push_back(v);
  }
  vector<int> visited(n+1, 0);
  vector<int> pathvisited(n+1, 0);
  vector<int> checkmark(n+1, 0);
  vector<int> safenode;

  for(int i=0;i<n;i++){
      if(!visited[i]){
          dfs(i,adj,visited,pathvisited,checkmark);
      }
  }
  for(int i=0;i<n;i++){
      if(checkmark[i]==1){
          safenode.push_back(i);
      }
  }
  return safenode;

}