#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Initialize edges
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Distance from a city to itself
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;

                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                );
            }
        }
    }

    int cntCity = INT_MAX;
    int cityNo = -1;

    for (int city = 0; city < n; city++) {

        int cnt = 0;

        for (int adjCity = 0; adjCity < n; adjCity++) {
            if (dist[city][adjCity] <= distanceThreshold) {
                cnt++;
            }
        }

        // <= ensures larger city number wins on ties
        if (cnt <= cntCity) {
            cntCity = cnt;
            cityNo = city;
        }
    }

    return cityNo;
}