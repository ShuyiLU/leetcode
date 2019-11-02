class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
		if( n== 0) return 0;
		if(costs[0].size() == 0) return 0;
		vector<vector<int>> dp(n, vector<int>(3, 0));  //dp[i][j]:ith room with jth color's min cost
		dp[0][0] = costs[0][0];
		dp[0][1] = costs[0][1];
		dp[0][2] = costs[0][2];
		for(int i=1; i<n; i++){
			for(int j=0; j<3; j++){
				dp[i][j] = costs[i][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);  //cost[i][j] + minimum with other 2 colors in i-1th room
			}
		}
		return min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
    }
};