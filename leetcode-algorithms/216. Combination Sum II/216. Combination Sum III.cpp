#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> tmp;
        backtrack(res, k, n, 1, 0, tmp);
        return res;
    }
    
    void backtrack(vector<vector<int> > &res, int k, int n, int index, int sum, vector<int> tmp){
    	if(k==0 && sum == n){
    		res.push_back(tmp);
    		return;
		}
		
		if(k>0 && sum == n) return;
		if(k == 0 && sum != n) return;
		
		for(int i=index;i<=9; i++){
			tmp.push_back(i);
			backtrack(res, k-1, n, i+1, sum+i, tmp);
			tmp.pop_back();
		}
		
		
	}
    
};
