#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int> > dp(d+1, vector<int>{});
        for(int i=0; i<d+1; i++) dp[i].resize(target+1);
        for(int i=0; i<d+1; i++){
        	for(int j=0; j<target+1; j++){
        		dp[i][j] = 0;
			}
		}
		for(int i=1; i<target+1; i++){
			if(i <= f) dp[1][i] = 1;
			else break;
		}
		
		for(int i=1; i<d+1; i++){
			for(int j=1; j<target+1; j++){
				for(int k=1; k<f && k<j; k++){
					dp[i][j] = (dp[i-1][j-k] + dp[i][j]) % ((int)pow(10, 9) + 7);
				}
			}
		}
		return dp[d][target];
		
    }
};
