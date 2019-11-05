class Solution {
public:
    vector<vector<int>> getFactors(int n) {
	    vector<vector<int>> res;
		vector<int> tmp;
        if(n==1) return res;
		backtrack(n, tmp, res, 2);
        res.pop_back();//remove 1&itself
        return res;
    }
	
	void backtrack(int n, vector<int> tmp, vector<vector<int>>&res, int cur){
		if(n == 1){
			res.push_back(tmp);
			tmp.clear();
			return;
		}
		
		for(int i=cur; i<=n; i++){
			if(n%i != 0) continue;
			tmp.push_back(i);
			backtrack(n/i, tmp, res, i);
			tmp.pop_back();
			
		}
	}
	
};