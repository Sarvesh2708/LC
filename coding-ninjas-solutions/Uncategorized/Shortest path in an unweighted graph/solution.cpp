vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here

	//create an adj list
	vector<vector<int>> adj(n+1);
	for(auto edge : edges){
		int u=edge.first;
		int v=edge.second;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//create a visited arr
	vector<int> parent(n+1,-1);

	//create a parent arr as a bool visited array
	vector<bool> visitedarr(n+1,false);

	queue<int> q;
	q.push(s);
	visited[s]=true;
	parent[s]=-1;
	

	//traverse using adj list
	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto neighbour : adj[node]){
			if(!visited[neighbour]){
				visited[neighbour]=true;
				parent[neighbour]=node;
				q.push(neighbour);

			}
		}
	}

	vector<int> path;
	int current = t;
	while(current!=-1){
		path.push_back(current);
		current = parent[current];

	}
	
	//reverse the list
	reverse(path.begin(),path.end());

	return path;

	
}
