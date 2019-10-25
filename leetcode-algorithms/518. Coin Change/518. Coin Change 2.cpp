#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
    	vector<int> dp;
    	dp.resize(amount+1);
    	dp[0] = 1;
        for(int i=0; i<coins.size(); i++){ // i=0, 只用第1种硬币组成j面值的可能； i=1， 用前2中硬币组成j的可能。 
        	for(int j=0; j<=amount; j++){
        		if(j >= coins[i]) dp[j] += dp[j-coins[i]];
			}
		}
		return dp[amount];
    }
};
