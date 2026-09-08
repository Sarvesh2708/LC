void toposort(int node,
              vector<vector<pair<int,int>>> &adj,
              vector<int> &visited,
              stack<int> &st)
{
    visited[node] = 1;

    for(auto it : adj[node]){
        int v = it.first;

        if(!visited[v]){
            toposort(v, adj, visited, st);
        }
    }

    st.push(node);
}


vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int,int>>> adj(n);

    // Build adjacency list
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    // Topological sort
    vector<int> visited(n, 0);
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            toposort(i, adj, visited, st);
        }
    }

    // Distance array
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    // Process nodes in topological order
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node] != INT_MAX &&
               dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }

    // Convert unreachable vertices to -1
    for(int i = 0; i < n; i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }

    return dist;
}
