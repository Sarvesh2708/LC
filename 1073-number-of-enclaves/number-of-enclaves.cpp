class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Mark current land as visited
        grid[row][col] = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m &&
               ncol >= 0 && ncol < n &&
               grid[nrow][ncol] == 1) {

                dfs(nrow, ncol, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // 1. DFS from first and last row
        for(int j = 0; j < n; j++) {

            if(grid[0][j] == 1)
                dfs(0, j, grid);

            if(grid[m-1][j] == 1)
                dfs(m-1, j, grid);
        }

        // 2. DFS from first and last column
        for(int i = 0; i < m; i++) {

            if(grid[i][0] == 1)
                dfs(i, 0, grid);

            if(grid[i][n-1] == 1)
                dfs(i, n-1, grid);
        }

        // 3. Count remaining land cells
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};