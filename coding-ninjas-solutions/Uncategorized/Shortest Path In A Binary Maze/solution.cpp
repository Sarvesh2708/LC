#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
    // Write your code here
    // define a proper queue {dist,{rownum,colnum}}
    
    if (matrix[src.first][src.second] == 0 ||
    matrix[dest.first][dest.second] == 0)
    return -1;
    
    queue<pair<int,pair<int,int>>>q;
    // a dist matrix 
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    dist[src.first][src.second] =0;
    q.push({0,{src.first,src.second}});
    
    if (src == dest)
    return 0;

    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        // traverse in all  4 dirs
        int d = it.first;
        int r = it.second.first;
        int c = it.second.second;
        for(int i=0;i<8;i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                matrix[nrow][ncol] == 1 &&
                d + 1 < dist[nrow][ncol])
            {
                dist[nrow][ncol] = d + 1;

                if (nrow == dest.first && ncol == dest.second)
                    return d + 1;

                q.push({d + 1, {nrow, ncol}});
            }
        }

    }
    return -1;
}