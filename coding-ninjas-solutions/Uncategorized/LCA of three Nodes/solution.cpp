int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    const int INF = 1e9;

    // Distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Distance from a vertex to itself
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Add edges
    for (auto &edge : edges) {
        int u = edge[0] - 1;
        int v = edge[1] - 1;
        int w = edge[2];

        dist[u][v] = w;
    }

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }
    }

    return dist[src - 1][dest - 1];
}
