class Solution {
public:

    bool solve(vector<int>& nums,int idx,int target,vector<vector<int>> &dp){
        if(target==0) return true;
        if(idx==0) return nums[idx]==target;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool nottake = solve(nums,idx-1,target,dp);
        bool take = false;

        if(nums[idx]<=target) take= solve(nums,idx-1,target-nums[idx],dp);
        return dp[idx][target] = (take || nottake);
    }

    bool canPartition(vector<int>& nums) {
        // if total sum is odd num return false
        int totalsum = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            totalsum+= nums[i];
        }
        if(totalsum%2!=0) return false;
        int target = totalsum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(nums,n-1,target,dp);
    }
};