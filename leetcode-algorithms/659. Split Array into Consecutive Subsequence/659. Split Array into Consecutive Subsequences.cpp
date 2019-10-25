#include<iostream>
#include<vector>
#include<map>

using namespace std; 

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
        map<int, int> need;
        for(auto num : nums){
			if(mp[num] == 0) continue;
			else if(need[num] > 0){
				need[num]--;
				need[num+1]++;
			}
			else if(mp[num+1] > 0 && mp[num+2] > 0){
				mp[num+1]--;
				mp[num+2]--;
				need[num+3]++; //num+3���Լ��뵽����������num+1�� num+2�ĺ�һ�� 
			}
			else return false;
			mp[num]--;
		}
		return true;
    }
};
