class Solution {
public:

    void bfsfunc(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0};

        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){       
                    int nrow = r + delRow[i];
                    int ncol = c+delCol[i];

                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                    && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m  = grid.size();
        int n  = grid[0].size();
        int cnt=0;
        // visited arr
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfsfunc(row,col,grid,vis);
                }

            }
        }
        return cnt;

    }
};








// class Solution {

//     void bfs(int row, int col,
//              vector<vector<int>>& visited,
//              vector<vector<char>>& grid) {

//         visited[row][col] = 1;

//         queue<pair<int, int>> q;
//         q.push({row, col});

//         while (!q.empty()) {

//             int row = q.front().first;
//             int col = q.front().second;
//             int n = grid.size();
//             int m = grid[0].size();

//             q.pop();

//             // Traverse in 4 neighbours
//             int delrow[] = {-1, 1, 0, 0};
//             int delcol[] = {0, 0, -1, 1};

//             for (int i = 0; i < 4; i++) {

//                 int nrow = row + delrow[i];
//                 int ncol = col + delcol[i];

//                 if (nrow >= 0 && nrow < n &&
//                     ncol >= 0 && ncol < m &&
//                     grid[nrow][ncol] == '1' &&
//                     !visited[nrow][ncol]) {

//                     visited[nrow][ncol] = 1;
//                     q.push({nrow, ncol});
//                 }
//             }
//         }
//     }

// public:

//     int numIslands(vector<vector<char>>& grid) {

//         int n = grid.size();
//         int m = grid[0].size();

//         vector<vector<int>> visited(n, vector<int>(m, 0));

//         int cnt = 0;

//         for (int row = 0; row < n; row++) {
//             for (int col = 0; col < m; col++) {

//                 if (!visited[row][col] &&
//                     grid[row][col] == '1') {

//                     cnt++;
//                     bfs(row, col, visited, grid);
//                 }
//             }
//         }

//         return cnt;
//     }
// };
