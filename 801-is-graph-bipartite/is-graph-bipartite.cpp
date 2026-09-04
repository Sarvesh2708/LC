class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        queue<int> q;

        for (int i = 0; i < n; i++) {

            if (visited[i] != -1)
                continue;

            q.push(i);
            visited[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto it : graph[node]) {

                    if (visited[it] == -1) {
                        visited[it] = !visited[node];
                        q.push(it);
                    }
                    else if (visited[it] == visited[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
