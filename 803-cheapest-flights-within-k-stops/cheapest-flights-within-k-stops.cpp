class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // dist[node] = minimum cost found so far
        vector<int> dist(n, INT_MAX);

        queue<pair<int, pair<int, int>>> q;

        // {number of flights, {node, cost}}
        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty()) {
            int flightsTaken = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;

            q.pop();

            // At most k stops => at most k + 1 flights
            if (flightsTaken == k + 1)
                continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (cost + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = cost + edgeWeight;

                    q.push({
                        flightsTaken + 1,
                        {adjNode, cost + edgeWeight}
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

