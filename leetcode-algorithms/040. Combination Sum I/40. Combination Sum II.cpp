class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
		set<vector<int>> res;
		vector<int> tmp;
		backtrack(candidates, res, tmp, target, 0, 0); 
        vector<vector<int> > ans;
        set<vector<int>> :: iterator it;
        for(it=res.begin(); it!=res.end(); it++){
            ans.push_back(*it);
        }
		return ans;
    }
	
	
	void backtrack(vector<int> &candidates, set<vector<int>> &res, vector<int> &tmp, int target, int index, int sum){
		if(sum == target){
			res.insert(tmp);
			return;
		}
		if(index > candidates.size() || sum > target) return;
		
		for(int i=index; i<candidates.size(); i++){
			tmp.push_back(candidates[i]);
			sum += candidates[i];
			backtrack(candidates, res, tmp, target, i+1, sum);
			sum -= candidates[i];
			tmp.pop_back();
		}
			
	}
};
