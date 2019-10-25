#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	if(nums.size() == 0) return 0;
    	if(nums.size() == 1) return nums[0];
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for(int i=1; i<=n-1; i++){
        	dp[i][i] = nums[i];
		}
        for(int len=0; len<n-2; len++){
        	for(int i=1; i+len<=n-2; i++){
        		for(int k=i; k<=i+len; k++){//Í¨¹ýlen¼ÆËãlen+1£¬ len+2... 
        			dp[i][i+len] = max(dp[i][i+len], dp[i][k-1] + dp[k+1][i+len] + nums[i-1]*nums[k]* nums[i+len+1]);
				}
			}
		}
		return dp[1][n-2];
    }
};


