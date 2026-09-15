vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    
    vector<int> dist(n + 1, 1000000000);
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1000000000 &&
                dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    vector<int> ans(n);

    for (int i = 1; i <= n; i++) {
        ans[i - 1] = dist[i];
    }

    return ans;
}
