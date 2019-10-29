#include<iostream>
#include<vector> 

using namespace std;
/*
class Solution {
public:
    int kthGrammar(int N, int K) {
        vector<vector<int> > dp(N+1, vector<int>{});
        if(N==0) return 0;
		dp[0].resize(1, 0);
		dp[1].resize(1, 0);
		for(int i=1; i<=N; i++) dp[i].resize(2 * dp[i-1].size());
		for(int i=2; i<=N; i++){
			for(int j=0; j<dp[i-1].size(); j++){
				if(dp[i-1][j] == 0){
					dp[i][2*j] = 0;
					dp[i][2*j+1] = 1;
				}
				else if(dp[i-1][j] == 1){
					dp[i][2*j] = 1;
					dp[i][2*j+1] = 0;
				}
			}
		} 
		return dp[N][K-1];
    }
};
*/

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 0) return 0;
        int ans = 0;
        if( kthGrammar(N-1, (K+1)/2) == 0 ){
        	if(K%2 == 0) ans = 1;
        	else ans = 0;
		}
		else if(kthGrammar(N-1), (K+1)/2 == 1){
			if(K%2 == 0) ans = 0;
        	else ans = 1;
		}
		return ans;
    }
};
