#include <bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<int>> &visited,int** &arr,vector<pair<int,int>> &combinations,
    int row0,int col0
){
    int n = visited.size();
    int m = visited[0].size();
    visited[row][col]=1;
    combinations.push_back({row-row0,col-col0});
    int delrow[] ={-1,0,1,0};
    int delcol[] ={0,1,0,-1};
    for(int i=0; i<4;i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && arr[nrow][ncol]==1){
            dfs(nrow,ncol,visited,arr,combinations,row0,col0);
        }
    }
}




int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    vector<vector<int>> visited(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && arr[i][j]==1){
                vector<pair<int,int>> combinations;
                dfs(i,j,visited,arr,combinations,i,j);
                st.insert(combinations);
            }
        }
    }
    return st.size();
}