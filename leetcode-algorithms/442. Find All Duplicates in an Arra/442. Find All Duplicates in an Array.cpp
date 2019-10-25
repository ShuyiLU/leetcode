#include<iostream>
#include<vector>
#include<cmath>

using namespace std; 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    	if(nums.size() == 0) return vector<int>{};
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
        	int n = abs(nums[i]) - 1;
        	if(nums[n] <0) res.push_back(abs(nums[i]));
        	else nums[n] = 0 - nums[n];
		}
        return res;      
    }
};
