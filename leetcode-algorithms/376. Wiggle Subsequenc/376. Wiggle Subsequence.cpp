#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);
        for(int i=1; i<nums.size(); i++){
        	if(nums[i] > nums[i-1]){
        		up[i] = down[i-1] + 1; //当前到下降时的最大长度 + 1
				down[i] = down[i-1]; 
			}
			else if(nums[i] < nums[i-1]){
				down[i] = up[i-1] + 1;
				up[i] = up[i-1];
			}
			else{
				up[i] = up[i-1];
				down[i] = down[i-1];
			}
		}
		return max(up[nums.size()-1], down[nums.size()-1]);
    }
};
