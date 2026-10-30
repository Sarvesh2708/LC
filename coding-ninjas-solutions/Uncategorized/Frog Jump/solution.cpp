#include <bits/stdc++.h> 


int solve(int ind,vector<int> &heights)



int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(ind==0) return 0;

    int left = solve(ind-1,heights)+abs(heights[ind]-heights[i-1]);
    // int right = solve(ind-2,heights)+abs(heights[ind]-heights[i-2]);
    int right = INT_MAX;

    if(ind>1){
        right = solve(ind-2,heights)+abs(heights[ind]-heights[i-2]);
    }
    return min(left,right);


}