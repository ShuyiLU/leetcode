bool cmp(vector<int> v1, vector<int> v2){
	if(v1[1] == v2[1]) return v1[0] < v2[0];
	return v1[1] < v2[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int cnt = 1;
		if(pairs.size() <= 1) return pairs.size();
		sort(pairs.begin(), pairs.end(), cmp);
		int last = 0;
		vector<int> dp(pairs.size(), 0);
		dp[0] = 1;
		for(int i=1; i<pairs.size(); i++){
			if(pairs[i][0] > pairs[last][1]){			
				dp[i] = dp[last] + 1;
                last = i;
			}
			else dp[i] = dp[i-1];
		}
		return dp[pairs.size()-1];
    }
};
