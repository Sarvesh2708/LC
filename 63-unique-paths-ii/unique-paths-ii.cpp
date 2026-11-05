class Solution {
public:

    int solve(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        
        if(i>=0&& j >=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 &&j==0 ) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int up = solve(i-1,j,obstacleGrid,dp);
        int left = solve(i,j-1,obstacleGrid,dp);

        return dp[i][j]= (up+left);
        
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));


        return solve(rows-1, cols-1, obstacleGrid,dp);

    }
};