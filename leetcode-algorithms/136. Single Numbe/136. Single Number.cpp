#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int ans = 0;
    	if(nums.size() == 0) return 0;
    	if(nums.size() == 1) return nums[0];
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
        	if(mp.count(nums[i]) == 0) mp[nums[i]] = 1;
        	else mp[nums[i]] += 1;
		}
		
		for(int i=0; i<nums.size(); i++){
			if(mp[nums[i]] == 1){
				ans = nums[i];
				break;
			} 
		}
		return ans;
		
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int ans = 0;
    	if(nums.size() == 0) return 0;
    	if(nums.size() == 1) return nums[0];
        for(int i=0; i<nums.size(); i++){
        	ans = ans ^ nums[i];
		}
		return ans;
		
    }
};

int main(){
}
