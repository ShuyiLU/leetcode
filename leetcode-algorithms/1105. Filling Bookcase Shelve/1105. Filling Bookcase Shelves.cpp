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
				h = max(h, books[j][1]); //��ǰһ����ʼ����֮ǰ���鵽��һ�㣬 ά����һ�����߶�
				w += books[j][0];
				if(w > shelf_width) break;
				dp[i] = min(dp[i], dp[j] + h);//��j+1��ʼ���µ�һ�㣬
											  //ǰj������С�߶ȼ���j+1��һ�����ĸ߶�
			}
		}
		return dp[n];
    }
};


///dp[i]: 0~jth����һ�㣬 j+1~i���µ�һ�㣬�����max h�ڣ�j+1,i)֮��
