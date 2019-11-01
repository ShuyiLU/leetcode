class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n=S.size();
        if (!n) return 0;
        vector<int> dp[2];
        dp[0].resize(n+1);
        dp[1].resize(n+1);
        for (int i=1; i<=n; i++) {
            dp[0][i]=dp[0][i-1]+(S[i-1]!='0');
            dp[1][i]=min(dp[0][i-1], dp[1][i-1])+(S[i-1]!='1');
        }
        return min(dp[0][n], dp[1][n]);
    }
};
