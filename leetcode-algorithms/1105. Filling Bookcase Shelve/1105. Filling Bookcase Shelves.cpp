class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
		vector<int> dp(n+1, INT_MAX);
		dp[0] = 0;
		for(int i=1; i<=n; i++){
			int h = 0;
			int w = 0;
			for(int j=i-1; j>=0; j--){
				h = max(h, books[j][1]); //从前一本开始，拿之前的书到下一层， 维持新一层最大高度
				w += books[j][0];
				if(w > shelf_width) break;
				dp[i] = min(dp[i], dp[j] + h);//从j+1开始是新的一层，
											  //前j本的最小高度加上j+1这一层最大的高度
			}
		}
		return dp[n];
    }
};


///dp[i]: 0~jth在上一层， j+1~i是新的一层，层高由max h在（j+1,i)之间
