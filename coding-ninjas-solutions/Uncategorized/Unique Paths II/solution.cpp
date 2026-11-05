
int solve(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        
        int MOD = 1e9 + 7;

    // Out of bounds
    if(i < 0 || j < 0) return 0;

    // Obstacle
    if(mat[i][j] == -1) return 0;

    // Starting point
    if(i == 0 && j == 0) return 1;

    // Already calculated
    if(dp[i][j] != -1) return dp[i][j];

        int up = solve(i-1,j,mat,dp);
        int left = solve(i,j-1,mat,dp);

        return dp[i][j]= (up+left);
        
}



int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));


    return solve(n-1, m-1, mat,dp);
}