#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int l, int u) {
    	vector<string> ans;
    	long long lower = l;
    	long long upper = u;
    	if(nums.size() == 0) return vector<string>{};
    	for(int i=0; i<nums.size(); i++){
    		while(i<nums.size() && nums[i] == lower){
    			i++;
    			lower++;
			} // lower = nums[i]
			if(i >= nums.size()) break;
			if(nums[i] == lower+1) ans.push_back(to_string(lower));
			else ans.push_back(to_string(lower) + "->" + to_string(nums[i]-1));
			lower = nums[i]+1;  //update lower
		}
		if(lower == upper) ans.push_back(to_string(lower));
		else if(lower < upper) ans.push_back(to_string(lower) + "->" + to_string(upper));
		return ans;
    }
};  


