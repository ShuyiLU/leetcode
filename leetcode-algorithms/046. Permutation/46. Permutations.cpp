#include<iostream>
#include<vector>
#include<cstring>

using namespace std; 


class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return vector<vector<int> > {};
        vector< vector<int> > res;
       // vector<int> tmp(n, 0);
    	backtrack(nums, res, 0, n);
		return res;    
    }
    
    void backtrack(vector<int>& nums, vector<vector<int> >& res, int i, int n){
    	if(i == n){
    		res.push_back(nums);
    		return;
		}
		
		if(i>n) return;
		
		for(int j=i; j<n; j++){
			swap(nums[i], nums[j]);
			backtrack(nums, res, i+1, n);
			swap(nums[j], nums[i]);
		}
	}
    
};


int main(){
	vector<int> v;
	int a;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	
	vector< vector <int> > res;
	Solution sol;
	res = sol.permute(v);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	
	
}
