class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>umpp;
        for(auto it:strs){
            string key = it;
            sort(key.begin(),key.end());
            umpp[key].push_back(it);
        }

        vector<vector<string>> ans;
        for (auto it : umpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};