class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umpp;
        for(auto it : nums){
            umpp[it]++;
        }
        //max heap
        priority_queue<pair<int,int>> pq;

        for(auto it : umpp){
            pq.push({it.second,it.first});
        }

        // it will be sorted in max order and now print
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};