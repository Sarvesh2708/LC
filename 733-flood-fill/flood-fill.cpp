class Solution {

    void dfs(int row,int col,vector<vector<int>> &image,vector<vector<int>> &ans,
int color,int deltarow[],
int deltacol[],int initialcol
){
    ans[row][col] = color;
    int n= image.size();
    int m = image[0].size();
    for(int i=0;i<4;i++){
        int nrow= row+deltarow[i];
        int ncol= col+deltacol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
        && image[nrow][ncol]==initialcol && ans[nrow][ncol]!=color){
            dfs(nrow,ncol,image,ans,color,deltarow,deltacol,initialcol);
        }
    }
}





public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       vector<vector<int>> ans = image;
    int initialcol=ans[sr][sc];
    int deltarow[] = {-1,0,1,0};
    int deltacol[] = {0,1,0,-1};
    dfs(sr,sc,image,ans,color,deltarow,deltacol,initialcol);
    return ans;
    }
};