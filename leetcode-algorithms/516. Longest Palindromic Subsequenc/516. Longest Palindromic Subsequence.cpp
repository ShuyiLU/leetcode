class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int l=0; l<n; l++) {
            for (int i=0; i+l<n; i++) {
                if (!l) dp[i][i]=1;
                else if (l==1) dp[i][i+1]=(s[i]==s[i+1])+1;
                else {
                    int j=i+l;
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                    dp[i][j]=max(dp[i][j], dp[i+1][j-1]+2*(s[i]==s[j]));
                }
            }
        }
        return dp[0][n-1];
    }
};
