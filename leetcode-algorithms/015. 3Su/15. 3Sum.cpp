#include<iostream>
#include<vector>
#include<set>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    	int m = nums.size();
    	vector<vector<int> > ans;
    	set<vector<int> > s;
    	vector<int> tmp;
    	for(int p=0; p<m-2; p++){
    		int l = p+1;
    		int r = m-1;
    		while(r<m && l<r){
    			if((nums[l] + nums[r]) == (0 - nums[p])){
    				//cout << "1";
    				tmp.push_back(nums[p]);
    				tmp.push_back(nums[l]);
    				tmp.push_back(nums[r]);
    				if(s.count(tmp) > 0) tmp.clear();
    				else {
    					s.insert(tmp);
    					tmp.clear();
					}
					l++;
				}
				
				else if(nums[l] + nums[r] < 0 - nums[p]) l++;
				else if(nums[l] + nums[r] > 0 - nums[p]) r--;
				
			}
		}
		return vector<vector<int> >(s.begin(), s.end());
    }
};
