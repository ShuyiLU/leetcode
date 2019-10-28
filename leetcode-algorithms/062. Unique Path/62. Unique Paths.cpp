class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp1, dp2;//dp1 for (i-1)th row, dp2 for ith row
        dp1.resize(n, 1);
        dp2.resize(n, 1);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp2[j] = dp1[j] + dp2[j-1];
            }
            dp1 = dp2;//calculate all in ith row, move to next row;
        }
        
        return dp2[n-1];
    }
};
