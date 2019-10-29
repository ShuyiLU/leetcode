#include<iostream>
#include<vector>
#include<map>

using namespace std;


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
        	if(nums[i] == 0) nums[i] = -1;
		}
		int max_len = INT_MIN;
		int sum = 0;
		map<int, int> mp;
		for(int i=0; i<nums.size(); i++){
			sum += nums[i];
            if(sum == 0) max_len = max(max_len, i+1);
			if(mp.count(sum) == 0){
				mp[sum] = i;
			}
			else{
				max_len = max(max_len, i-mp[sum]);
			}
		}
		return max_len;
    }
};
