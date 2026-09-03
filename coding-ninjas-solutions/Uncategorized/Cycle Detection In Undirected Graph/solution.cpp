#include <bits/stdc++.h>#include <bits/stdc++.h>
using namespace std;using namespace std;
  
  
string cycleDetection(vector<vector<int>>& edges, int n, int m)string cycleDetection(vector<vector<int>>& edges, int n, int m)
{{
    // Build an adjacency list    // Build an adjacency list
    vector<vector<int>> adj(n + 1);    vector<vector<int>> adj(n + 1);
  
    for (int i = 0; i < m; i++)    for (int i = 0; i < m; i++)
    {    {
        int u = edges[i][0];        int u = edges[i][0];
        int v = edges[i][1];        int v = edges[i][1];
  
        adj[u].push_back(v);        adj[u].push_back(v);
        adj[v].push_back(u);        adj[v].push_back(u);
    }    }
  
    // Create a visited array    // Create a visited array
    vector<int> visited(n + 1, 0);    vector<int> visited(n + 1, 0);
  
    // Check all components    // Check all components
    for (int start = 1; start <= n; start++)    for (int start = 1; start <= n; start++)
    {    {
        if (visited[start])        if (visited[start])
            continue;            continue;
  
        queue<pair<int, int>> q;        queue<pair<int, int>> q;