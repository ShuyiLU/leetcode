#include<iostream>
#include<vector>

using namespace std;
 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> temp(nums.size(), -1);
        int i=0;
        int j=nums.size()-1;
        for(int k=0; k<nums.size(); k++){
        	if(nums[k] == 0){
        		temp[i] = 0;
        		i++;
			}
			else if(nums[k] == 2){
				temp[j] = 2;
				j--;
			}
			else continue;
		}
		
		for(int k=0; k<nums.size(); k++){
			if(temp[k] == 0) nums[k] = 0;
			else if(temp[k] == 2) nums[k] = 2;
			else nums[k] = 1;
		}
		
    }
};
