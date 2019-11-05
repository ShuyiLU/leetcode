//dp(i, j, k) = max(dp(i, j, k-1), 1+dp(i-c1, j-c2, k-1));

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
		int size = strs.size();
		if(size == 0) return 0;
		vector<vector<int>> cnt(size, vector<int>(2, 0));
		for(int i=0; i<size; i++){
			string st = strs[i];
			for(int j=0; j<st.length(); j++){
				if(st[j] == '0') cnt[i][0]++;
				if(st[j] == '1') cnt[i][1]++;
			}
		}
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(size, 0)));
		
		for(int count=0; count<size; count++){
			int c0 = cnt[count][0];
			int c1 = cnt[count][1];
			for(int i=m; i>=0; i--){
				for(int j=n; j>=0; j--){
					if(i >= c0 && j>= c1){
						if(count == 0) dp[i][j][0] = 1;
						else{
							dp[i][j][count] = max(dp[i][j][count-1], 1+dp[i-c0][j-c1][count-1]);
							//i个0， j个1，组成到第count个时最大的单词数
							//放进第count个字串单词多还是原来单词数更多
						}
					}
					else{
						if(count == 0) dp[i][j][0] = 0;
						else dp[i][j][count] = dp[i][j][count-1];
					}
				}
			}
		}
		return dp[m][n][size-1];
    }
};