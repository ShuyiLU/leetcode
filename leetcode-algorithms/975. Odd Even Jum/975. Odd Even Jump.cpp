#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;
/*
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        vector<vector<int> > dp;
		dp.resize(A.size());
		map<pair<int, int>, int> mp;
		/*
		for(int i=0; i<A.size(); i++){
			dp[i].resize(A.size());
		} 
		for(int i=0; i<A.size(); i++){
			for(int j=0; j<A.size(); j++){
				dp[i][j] = -1;
			}
		}
		
		int n = A.size();
		int cnt = 1;
		for(int i=0; i<n; i++) 
		{
			dp[i].push_back({});
			dp[i][0] = A[i];
			mp[make_pair(i, 0)] = i;
		}
		//dp[i][k]: start from i, reachable position of kth jump
		for(int i=0; i<n; i++){
			for(int k=1; k<n; k++){
            if(dp[i][k-1] == -1)break;
            dp[i].push_back({});
            dp[i][k] = -1;
				for(int j=mp[make_pair(i,k-1)]+1; j<n; j++){
					if(k%2 == 1){
						if(A[j] >= dp[i][k-1] && (A[j]<dp[i][k] || dp[i][k]<0)) {
							dp[i][k] = A[j];
							mp[make_pair(i, k)] = j;
						}
						
					}
					else{
						if(A[j] <= dp[i][k-1] && (A[j]>dp[i][k] || dp[i][k]<0)) {
							dp[i][k] = A[j];
							mp[make_pair(i, k)] = j;
						}
					}
				}
				if(dp[i][k] < 0) break;
				else if(dp[i][k] == A[n-1]){
					cnt++;
					break;
				}
			}
		}/*
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return cnt;
    }
};
*/

