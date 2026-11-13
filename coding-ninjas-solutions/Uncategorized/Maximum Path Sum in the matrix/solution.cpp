#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m= matrix.size();
    int n= matrix[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    
    for(int j=0;j<n;j++) dp[0][j] = matrix[0][j];


    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            int up= matrix[i][j]+dp[i-1][j];
            int downleft= matrix[i][j];
            if(j-1>=0) downleft+=dp[i-1][j-1];
            else downleft+=-1e8;
            int downright= matrix[i][j];
            if(j+1<n) downright+=dp[i-1][j+1];
            else downright+=-1e8;
            dp[i][j] = max(up,max(downleft,downright));
        }
    }
    int maxi = -1e8;
    for(int j=0;j<n;j++){
        maxi = max(maxi,dp[m-1][j]);
    }
    return maxi;


}