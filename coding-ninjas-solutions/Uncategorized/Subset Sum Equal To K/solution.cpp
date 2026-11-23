#include <bits/stdc++.h> 

bool f(int index,vector<int>& arr, int target,vector<vector<int>> &dp){
    if(target==0) return true;
    if(index==0) return arr[index]==target;

    if(dp[index][target]!=-1) return dp[index][target];
    bool nottake = f(index-1,arr,target,dp);
    bool take = false;
    
    f(index-1,arr,target-arr[index]);

    if(arr[index]<=target) take= f(index-1,arr,target-arr[index]);


    return take|nottake;





}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,arr,k,dp);
}