#include<iostream>
#include<vector>

using namespace std;

class Solution {
public: 
	int cnt = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
		dfs(0, nums, S, 0);
		return cnt;
    }
    void dfs(int index, vector<int> &nums, int S, int sum){
    	if(index == nums.size() && sum == S) {
    		cnt++;
    		return;
		}
		if(index == nums.size()) return;
		dfs(index+1, nums, S, sum+nums[index]);
		dfs(index+1, nums, S, sum-nums[index]);
	}
};


