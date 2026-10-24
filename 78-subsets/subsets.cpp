class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findsubsets(0,nums,ds,ans);
        return ans;
    }

    

    void findsubsets(int idx,vector<int>& nums,vector<int> &ds,vector<vector<int>>& ans){
        if(idx==nums.size()){
             ans.push_back(ds);
             return;
             };
        ds.push_back(nums[idx]);
        findsubsets(idx+1,nums,ds,ans);
        ds.pop_back();
        findsubsets(idx+1,nums,ds,ans);
    }

};