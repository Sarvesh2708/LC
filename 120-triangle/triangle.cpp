class Solution {

public:

    int f(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>&dp){
        if(i==n-1){
            return triangle[n-1][j];
        }
        if(dp[i][j]!= INT_MIN) return dp[i][j];

        int down = triangle[i][j]+f(i+1,j,triangle,n,dp);
        int dig = triangle[i][j]+f(i+1,j+1,triangle,n,dp);

        return dp[i][j]= min(down,dig);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n, INT_MIN));
        // int n = triangle[m-1].size();
        return f(0,0,triangle,n,dp);
    }
};