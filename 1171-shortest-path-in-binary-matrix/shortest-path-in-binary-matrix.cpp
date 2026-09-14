class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // define a queue
        queue<pair<int,pair<int,int>>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        if (n == 1)
        return 1;
        dist[0][0] = 1;
        q.push({1,{0,0}});
        //Need to write source and destination 
        
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<8;i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 0 &&
                d + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = d + 1;

                    if (nrow == n-1 && ncol == m-1)
                    return d + 1;

                    q.push({d+1,{nrow,ncol}});
                }
            }

        }
        return -1;

    }
};