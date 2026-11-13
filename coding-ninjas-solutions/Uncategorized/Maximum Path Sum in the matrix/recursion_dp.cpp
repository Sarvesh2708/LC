#include <bits/stdc++.h> 


int f(int i,int j,vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    if(j<0 || j>=m) return INT_MIN;
    if(i==0) return matrix[0][j];
    // int up = matrix[i][j] + f(i-1,j,matrix);
    // int digleft = matrix[i][j] + f(i-1,j-1,matrix);
    // int digright = matrix[i][j] + f(i-1,j+1,matrix);
    // return max(up,max(digleft,digright));
    int up = matrix[i][j] + f(i-1,j,matrix);

    int left = matrix[i][j] + f(i-1,j-1,matrix);

    int right = matrix[i][j] + f(i-1,j+1,matrix);

    return max(up, max(left, right));

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[n].size();
    int maxi = -1e8;

    for(int j=0;j<m;j++){
      maxi = max(maxi,f(n-1,j,matrix));
    }
    return maxi;
}
