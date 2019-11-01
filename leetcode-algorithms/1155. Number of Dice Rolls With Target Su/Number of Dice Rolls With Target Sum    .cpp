class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int> > dp(d+1, vector<int>{});
        for(int i=0; i<d+1; i++) dp[i].resize(target+1);
        for(int i=0; i<d+1; i++){
            for(int j=0; j<target+1; j++){
                dp[i][j] = 0;
            }
        }
        for(int i=1; i<=f; i++){
            if(i<= target) dp[1][i] = 1;
        }
        for(int i=1; i<=d; i++){
            for(int j=1; j<=target; j++){
                for(int x=1; x<=f&&x<j; x++){
                    dp[i][j] = (dp[i-1][j-x] + dp[i][j]) % ((int)pow(10, 9) + 7) ;//last dice is x, accumulate
                }
            }
        }
        return dp[d][target] ;
    }
};
