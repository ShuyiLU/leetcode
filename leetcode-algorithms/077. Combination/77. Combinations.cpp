#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int> > res;
        if(k == 0 || n==0 || k > n) return res;
        backtrack(k, n, 0, tmp, res);
        return res;
    }
    
    void backtrack(int k, int n, int i, vector<int> tmp, vector<vector<int> >&res){
    	if(k==0){
    		res.push_back(tmp);
    		tmp.clear();
    		return;
		}
		
		for(int p=i+1; p<=n; p++){
			tmp.push_back(p);
			backtrack(k-1, n, p, tmp, res);
			tmp.pop_back();
		}
		
	}
    
};
