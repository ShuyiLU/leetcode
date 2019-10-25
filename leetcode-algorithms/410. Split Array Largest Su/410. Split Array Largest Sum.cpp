#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        //dp[i][k] : input spilt into k part with nums[0]~nums[i], max sum
        int n = nums.size();
        vector<vector<long>>dp(n, vector<long>(m+1, int_max));
		vecto<long> sum(n,0);
		for(int i=0; i<n; i++){
			if(i == 0) sum[i] = nums[0];
			else sum[i] = sum[i-1] + nums[i];
		}
		int  = min(m, i+1);
		
		for(int i=0; i<maxDivide; i++){
			dp[i][1] = sum[i];
		} 
		
		for(int i=0; i<n; i++){
			
			for(int k=1; k<=maxDivide; k++){  //k group
				
				for(int j=i; j>=k-1; j--){ //0~i into k group, possibility: (i, i-1), (i, i-1, i-2), (i, i-1, ..., k-1)
										   //0~k-2 can be mostly into k-1 groups
					long partsum = sum[i]-sum[j] + nums[j];//(j~i's sum')
					if(partsum > dp[i][k]) break;
					dp[i][k] = min(dp[i][k], max(partsum, dp[j-1][k-1])); //j~i: 1group, 0~j-1: k-1 group, max in the k groups
				}
			}
		}
		return dp[n-1][m];
    }
};


/*

for(int i=0; i<n; i++){
	for(int k=1; k<=m; k++){
		if(k == 1){
			dp[i][k] = sum[i];
			continue;
		}
		for(int j=i; j>=k-1; j--){
			long part = sum[i]-sum[j] + nums[j];
			if(part > dp[i][k]) continue;
			dp[i][k] = min(dp[i][k], max(part, dp[j-1][k-1]));
		}
	}
}

*/


bool cansplit(vector<int)
