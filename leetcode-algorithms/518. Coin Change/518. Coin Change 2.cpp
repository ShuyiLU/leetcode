#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
    	vector<int> dp;
    	dp.resize(amount+1);
    	dp[0] = 1;
        for(int i=0; i<coins.size(); i++){ // i=0, ֻ�õ�1��Ӳ�����j��ֵ�Ŀ��ܣ� i=1�� ��ǰ2��Ӳ�����j�Ŀ��ܡ� 
        	for(int j=0; j<=amount; j++){
        		if(j >= coins[i]) dp[j] += dp[j-coins[i]];
			}
		}
		return dp[amount];
    }
};
