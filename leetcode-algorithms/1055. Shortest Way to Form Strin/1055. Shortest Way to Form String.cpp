#include<iostream>
#include<vector>
#include<cstring>

using namespace std; 


/*substring
class Solution {
public:
    int shortestWay(string source, string target) {
        int len = target.length();
        vector<vector<int> > dp (len, vector<int>{});
        for(int i=0; i<len; i++) dp[i].resize(len);
        for(int i=0; i<len; i++){
        	for(int j=0; j<len; j++){
        		dp[i][j] = -1;
			}
		}
		
		for(int i=0; i<len; i++){
			for( int j=0; j<len; j++){
				if( i == j ){
					if(source.find(target[i]) == string :: npos) return -1;
					else dp[i][i] = 1;
				}
				else{
					string str = target.substr(i, j-i+1);
					if(source.find(str) != string :: npos) dp[i][j] = 1;
				}
			}

		}
		
		for(int i=0; i<len; i++){
			for(int j=0; j<len; j++){

					for(int k=i; k<j; k++){
						if(dp[i][k] > 0 && dp[k+1][j] > 0){
							if(dp[i][j] > 0) dp[i][j] = min(dp[i][k]+dp[k+1][j], dp[i][j]);
							else dp[i][j] = dp[i][k] + dp[k+1][j];
						}
					}
				

			}
		}
		
		for(int i=0; i<len; i++){
			for(int j=0; j<len; j++){
				cout << "dp " << i << " " << j  << ": " << dp[i][j] <<endl;
			}
		}
		
		
		return dp[0][len-1];
    }
};
*/

/*subsequence*/
class Solution {
public:
    int shortestWay(string source, string target) {
    	int n = source.length();
        int m = target.length();
        vector<vector<int> > dp (n, vector<int>{});
        for(int i=0; i<n; i++) dp[i].resize(m);
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		dp[i][j] = 0;
			}
		}
		
		for(int i=0; i<m; i++){
			if(source.find(target[i]) == string :: npos) return -1;
		}
		int flag = 0;
		for(int i=0; i<n; i++){
			if(flag == 1) dp[i][0] = 1;
			else{
				if(source[i] != target[0]) dp[i][0] = 0;
				else {
					dp[i][0] = 1;
					flag = 1;
				}
			}		
		}
		
		int cnt=0;
		for(int i=0; i<m; i++){
			if(source[0] == target[i]){
				cnt++;
			}
			dp[0][i] = cnt;
		}
		
		for(int i=1; i<n; i++){
			for(int j=1; j<m; j++){
				if(source[i] == target[j]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << "dp " << i << " " << j  << ": " << dp[i][j] <<endl;
			}
		}
		return dp[n-1][m-1]; 
    }
};

int shortestWay(string source, string target) {
	int n = source.length();
	int cnt = 0;
	while(target.length()){
		int s_i = 0, t_i = 0;
		while(s_i < source.length() && t_i < target.length()){
			if(source[s_i] == target[t_i]) t_i++;
			s_i++;
		}
		cnt++;
		if(t_i == 0) return -1;
		else target = target.substr(t_i); 
	}
	return cnt;
};


int main(){
	string s;
	string t;
	cin >> s >> t;
	Solution sol;
	cout << sol.shortestWay(s, t) << endl;
}
