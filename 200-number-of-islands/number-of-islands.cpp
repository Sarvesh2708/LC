class Solution {

    void bfs(int row, int col,
             vector<vector<int>>& visited,
             vector<vector<char>>& grid) {

        visited[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            int n = grid.size();
            int m = grid[0].size();

            q.pop();

            // Traverse in 4 neighbours
            int delrow[] = {-1, 1, 0, 0};
            int delcol[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' &&
                    !visited[nrow][ncol]) {

                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (!visited[row][col] &&
                    grid[row][col] == '1') {

                    cnt++;
                    bfs(row, col, visited, grid);
                }
            }
        }

        return cnt;
    }
};
