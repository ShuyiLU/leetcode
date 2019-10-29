#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for(int i=2; i<=n; i++){
			for(int j=0; j<i; j++){
				dp[i] = max(max(dp[j]*dp[i-j], dp[j]*(i-j)), max(j*(i-j), j*dp[i-j]));
			}
		}
		return dp[n];
    }
};
