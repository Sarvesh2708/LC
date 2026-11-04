#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	//create a dp vector 
	// vector<vector<int>>dp(m,vector<int>(n,-1));
	vector<int>>dp(m,0);
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			//so from the position m-1 and n-1 we can either traverse up or left
			// if(i==0 && j==0) return 1;
			// else{
			// 	int up=0;
			// 	int left=0;

			// 	if(i>0) up = dp[i];
			// 	if(j>0) left = ;
			// 	dp[i][j] = up + left;
			// }
			


		}
	}
	return dp[m-1][n-1];
	
}

















// #include <bits/stdc++.h> 
// int uniquePaths(int m, int n) {
// 	// Write your code here.
// 	//create a dp vector 
// 	// vector<vector<int>>dp(m,vector<int>(n,-1));
// 	vector<int>>dp(m,0);
// 	if(i==0 && j==0) return 1;
// 	if(i<0 || j<0) return 0;
// 	for(int i=0;i<m;i++){
// 		for(int j=0;j<n;j++){
// 			//so from the position m-1 and n-1 we can either traverse up or left
// 			// if(i==0 && j==0) return 1;
// 			// else{
// 			// 	int up=0;
// 			// 	int left=0;

// 			// 	if(i>0) up = dp[i];
// 			// 	if(j>0) left = ;
// 			// 	dp[i][j] = up + left;
// 			// }
			


// 		}
// 	}
// 	return dp[m-1][n-1];
	
// }