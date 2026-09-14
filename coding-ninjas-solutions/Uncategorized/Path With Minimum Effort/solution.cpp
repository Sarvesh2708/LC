int minimumTimeTakingPath(vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int,int>>,
               vector<pair<int, pair<int,int>>>,
               greater<pair<int, pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] =0;
        pq.push({0,{0,0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int  r= it.second.first;
            int c = it.second.second;

            if(r==n-1 && c==m-1) return d;
            for(int i=0;i<4;i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                
                if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m
                )
            {
                int newEffor = max(abs(heights[r][c]-heights[nrow][ncol]),d);
                if(newEffor < dist[nrow][ncol]){
                    dist[nrow][ncol] = newEffor;
                    pq.push({newEffor,{nrow,ncol}});
                    
                }
            }
            }
        }
    return 0;
    }
}