#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
		vector<int> dp1(n-1, 0);
		vector<int> dp2(n-1, 0);
		
		for(int i=0; i<n-1; i++){
			if(i == 0) dp1[i] = nums[0];
			else if(i == 1) dp1[i] = max(nums[0], nums[1]);
			else dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
		}
		for(int i=0; i<n-1; i++){
			if(i == 0) dp2[i] = nums[1];
			else if(i == 1) dp2[i] = max(nums[1], nums[2]);
			else dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i+1]);
		}
		return max(dp1[n-2], dp2[n-2]);
		
    }
};
