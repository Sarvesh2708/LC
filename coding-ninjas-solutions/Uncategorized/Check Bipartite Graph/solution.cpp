bool dfs(int node, int col, vector<int>& visited, vector<int> adj[]) {
    visited[node] = col;

    for (auto it : adj[node]) {
        if (visited[it] == -1) {
            if (dfs(it, !col, visited, adj) == false)
                return false;
        }
        else if (visited[it] == col) {
            return false;
        }
    }

    return true;
}

bool isGraphBirpatite(vector<vector<int>>& edges) {
    int n = edges.size();

    vector<int> adj[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (edges[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> visited(n, -1);

    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            if (dfs(i, 0, visited, adj) == false)
                return false;
        }
    }

    return true;
}
