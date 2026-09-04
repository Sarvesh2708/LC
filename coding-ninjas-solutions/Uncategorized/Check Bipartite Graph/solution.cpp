#include <queue>

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	queue<int> q;
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
	q.push(0);
	visited[0]=0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto it:adj[node]){
			if(visited[it]==-1){
				visited[it] = !visited[node];
				q.push(it);
			}
			else if(visited[it]==visited[node]){
				return false;
			}
		}
	}
	return true;



	 
}