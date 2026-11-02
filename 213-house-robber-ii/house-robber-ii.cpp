class Solution {
public:

    int myfunc(vector<int> arr){
        int n = arr.size();
        int prev = arr[0];
        int prev2 = 0;
        
        for(int i=1;i<n;i++){
            int take = arr[i];
            if(i>1) take+=prev2;
            int nottake =0 + prev;
            int curr = max(take,nottake);
            prev2 = prev;
            prev  = curr;
        }
        return prev;
        
        }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            //for excluding the first element
            if(i!=0) temp1.push_back(nums[i]);
            //for excluding the last element
            if(i!=n-1) temp2.push_back(nums[i]);
            //list is created
        }
        return max(myfunc(temp1),myfunc(temp2));
    }
};