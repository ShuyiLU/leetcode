class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
		if(n == 0) return 0;
		int m = A[0].size();
		if(m == 0) return 0;
		int res = 0;
		vector<vector<int> > dp(n, vector<int>(m, INT_MAX));
		for(int i=0; i<m; i++) dp[0][i] = A[0][i];
		for(int i=1; i<n; i++){
			for(int j=0; j<m; j++){
				if(j == 0){
					dp[i][j] = min(dp[i-1][j] + A[i][j], dp[i-1][j+1] + A[i][j]);
				}
				else if(j == m-1){
					dp[i][j] = min(dp[i-1][j] + A[i][j], dp[i-1][j-1] + A[i][j]);
				}
				else{
					dp[i][j] = min(dp[i-1][j] + A[i][j], min(dp[i-1][j-1] + A[i][j], dp[i-1][j+1]+A[i][j]));
				}
			}
		}
		res = dp[n-1][0];
		for(int i=0; i<m; i++){
			if(dp[n-1][i] < res) res = dp[n-1][i]; 
		}
		return res;
    }
};
