#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	int res;
        for(int i=0; i<nums.size(); i++){
        	int tmp = abs(nums[i]);
        	if(nums[tmp-1] > 0) nums[tmp-1] *= (-1);
        	else{
        		res = abs(nums[i]);
        		break;
			}
		}
		return res;
    }
};
