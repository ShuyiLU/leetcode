#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    	int sum = 0;
        for(int i=0; i<nums.size(); i++){
        	sum += nums[i];
		}
		int n = nums.size();
		if(sum % k != 0) return false;
		
		int t = sum/k;
		vector<bool> visited(n, 0);
		
		return dfs(nums, visited, k, t, n, 0 0);
		
		
		
    }
    
    
    bool dfs(vector<int>& nums, vector<bool>& visited, int k, int t, int n, int index, int curSum){
    	if(k == 1){
			return true;
		}
		else if(curSum > t) return false;
		else if(curSum == t) return dfs(nums, visited, k-1, t, n, 0, 0); //开始新的划分 
		else{
			for(int i=index; i<n; i++){
				if(visited[i] == 0){
					visited[i] = 1;
					if(dfs(nums, visited, k, t, n, index+1,curSum + nums[i])) return true; //完成一次划分 
					visited[i] = 0;
				}
			}
			return false;
		}
		
		
		
	}
    
    
    
    
};

