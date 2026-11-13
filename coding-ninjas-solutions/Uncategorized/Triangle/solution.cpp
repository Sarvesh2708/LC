#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<int>front(n,0);
	vector<int>curr(n,0);

	for(int j=0;i<j-1;j++) front[j] = triangle[n-1][j];

	//start from last sec row 
	for(int i=n-2;i>=0;i--){
		for(int j = 0; j < n; j++)
		
			int down = triangle[i][j]+front[j];
			int dig = triangle[i][j]+front[j+1];
			curr[j] = min(down,dig);
		}
		front = curr;

	}
	return front[0];



}