bool dfs(int node,vector<vector<int>> &adj,vector<int> &visited,vector<int> &pathvisited){
  visited[node]=1;
  pathvisited[node]=1;
  for(auto it:adj[node]){
    if(!visited[it]){
      if(dfs(it,adj,visited,pathvisited)==true) return true;
    }
  else if(pathvisited[it]){
    return true;
  }
  }
  pathvisited[node]=0;
  return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>> adj(n + 1);


  for (auto edge : edges) {
      int u = edge.first;
      int v = edge.second;

      adj[u].push_back(v);
  }
  vector<int> visited(n+1, 0);
  vector<int> pathvisited(n+1, 0);


  for(int i=0;i<n;i++){
    if(!visited[i]){
      if(dfs(i,adj,visited,pathvisited)==true) return 1;
    }
  }
  return 0;

}