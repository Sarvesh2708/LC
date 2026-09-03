#include <vector>
using namespace std;


void dfs(int row,int col, vector<vector<int>> &visited,char** &arr
int delrow[],int delcol[],int n,int m
){  
    int n = arr.size();
    int m = arr[0].size();
    visited[row][col]=1;
    //check for top bottom left right;
    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && arr[nrow][ncol]=='O'){
            dfs(nrow,ncol,visited,arr,delrow,delcol,n,m);
        }
    }
}





void replaceOWithX(char** arr, int n, int  m)
{
    //Write your code here   
    vector<vector<int>> visited(n,vector<int>(m,0));
    int delrow[] ={-1,0,1,0};
    int delcol[] ={0,1,0,-1};
    // iterate the top and last row 
    for(int j=0;j<m;j++){
        if(arr[0][j] == 'O' && !visited[0][j]){
            dfs(0,j,visited,arr,delrow,delcol,n,m);
        }
        if(arr[n-1][j] == 'O' && !visited[n-1][j]){
            dfs(n-1,j,visited,arr,delrow,delcol,n,m);
        }
    }
    // for the columns
    for(int i=0;i<n;i++){
        // for first col
        if(arr[i][0]=='O' && !visited[i][0]){
            dfs(i,0,visited,arr,delrow,delcol,n,m);
        }
        if(arr[i][m-1]=='O' && !visited[i][m-1]){
            dfs(i,m-1,visited,arr,delrow,delcol,n,m);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && arr[i][j]=='O'){
                arr[i][j]='X';
            }
        }
    }
    return arr;

}