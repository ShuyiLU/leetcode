#include<iostream>
#include<vector>
#include<set>

using namespace std; 

class Solution {
	
public:
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int> > ans;
        vector<int> tmp;
        dfs(nums, ans, tmp, 0);
        return vector<vector<int> > (ans.begin(), ans.end());
    }
    
    void dfs(vector<int>& nums, set<vector<int> >& ans,  vector<int>& tmp, int k){
    	if(tmp.size() >= 2){
    		ans.insert(tmp);
		}
		
		for(int i=k; i<nums.size(); i++){
			if(tmp.empty() || nums[i] >= tmp.back()){
				tmp.push_back(nums[i]);
				dfs(nums, ans, tmp, i+1);
				tmp.pop_back();
			}
		}
		
	}
    
    
};
