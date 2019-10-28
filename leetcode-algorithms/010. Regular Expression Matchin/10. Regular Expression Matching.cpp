class Solution {
public:
    bool isMatch(string s, string p) {
        const int n=s.size();
        const int m=p.size();
        bool dp[n+1][m+1]={};
        dp[0][0]=true;
        for (int i=0; i<=n; i++) for (int j=1; j<=m; j++) {
            if (!i) {
                if (p[j-1]=='*') dp[i][j]|=dp[i][j-2];
                continue;
            }
            char c1=s[i-1], c2=p[j-1];
            if (j<m&&p[j]=='*') continue;
            if (c2=='*') {
                c2=p[j-2];
                dp[i][j]|=dp[i][j-2];
                if (c2=='.'||c2==c1) {
                    dp[i][j]|=dp[i-1][j-2];
                    dp[i][j]|=dp[i-1][j];
                }
            }
            else if (c1==c2||c2=='.') {
                dp[i][j]|=dp[i-1][j-1];
            }
        }
        // for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        //     cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        // }
        return dp[n][m];
    }
};
