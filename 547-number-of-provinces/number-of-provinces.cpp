class Solution {

private:
    void dfs(int node,vector<int> adjls[],vector<int> &vis){
        vis[node]=1;
        for(auto it:adjls[node]){
            if(!vis[it]){
                dfs(it,adjls,vis);
            }
        }
    }



public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt=0;
        // create and adj lisst
        vector<int>adjls[n];
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }


        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};