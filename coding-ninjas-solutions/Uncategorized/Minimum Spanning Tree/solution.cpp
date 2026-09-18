#include <queue>
#include <vector>
#include <functional>
using namespace std;



int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
  priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
  vector<vector<pair<int, int>>> adj(n);

  for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
  
  vector<int> visited(n,0);
  pq.push({0,0});
  int sum=0;
  while(!pq.empty()){
    auto it = pq.top();
    pq.pop();

    int wt = it.first;
    int node = it.second;

    if(visited[node]==1) continue;
    visited[node]=1;
    sum += wt;
    for(auto it : adj[node] ){
      int adjNode = it.first;
      int edw = it.second;
      if(!visited[adjNode]){
        pq.push({edw,adjNode});
      }
    }
  }
  return sum;
}