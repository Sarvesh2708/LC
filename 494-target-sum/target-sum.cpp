
class Solution {
public:
    int f(int idx, int sum, int target,
          vector<int>& nums,
          vector<vector<int>>& dp,
          int offset) {

        if(idx == nums.size()) {
            return sum == target ? 1 : 0;
        }

        if(dp[idx][sum + offset] != -1) {
            return dp[idx][sum + offset];
        }

        int add = f(idx + 1, sum + nums[idx],
                    target, nums, dp, offset);

        int sub = f(idx + 1, sum - nums[idx],
                    target, nums, dp, offset);

        return dp[idx][sum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;

        for(int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        int offset = total;

        vector<vector<int>> dp(
            nums.size(), vector<int>(2 * total + 1, -1)
        );

        return f(0, 0, target, nums, dp, offset);
    }
};
