#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int cnt = 0;
        set<int> s;
        int index = 0;
        int i=0;
        while(i<n && s.size()){
        	if(s.count(nums[i]) > 0){
        		res = max(res, cnt);
        		index++;
        		i = index;
        		cnt = 0;
        		continue;
			}
			cnt++;
			s.insert(i);
			i = nums[i];
		}
		return res;
    }
};
