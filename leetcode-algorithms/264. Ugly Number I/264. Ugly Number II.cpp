class Solution {
public:
    int nthUglyNumber(int n) {
		vector<int> dp(n);
		dp[0] = 1;
		int l2=0, l3=0, l5=0;
		for(int i=1; i<n; i++){
			dp[i] = min(min(dp[l2]*2, dp[l3]*3), dp[l5]*5);
			if(dp[i] == dp[l2]*2) l2++; //下一次新数*2 和旧数*3， 旧数*5比较
			if(dp[i] == dp[l3]*3) l3++;
			if(dp[i] == dp[l5]*5) l5++;
		}
		return dp[n-1];
    }
};