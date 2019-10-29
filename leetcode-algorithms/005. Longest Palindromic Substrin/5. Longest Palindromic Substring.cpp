#include<iostream>
#include<vector> 
#include<map>
#include<queue>
#include<string>
#include<cstring>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
    	//int f[1001][1001];
    	int n = s.length();
    	int f[n+1][n+1];
    	//int d[n+1][n+1];
    	memset(f,0,sizeof(f));
    	
		for(int k=0; k<n; k++){
			int i=0; 
			int j=k;
			for(;i<n&&j<n;i++,j++){
				if(i == j) {
					f[i][j] = 1;
					continue;
				}
				if(j-i == 1){
    				if(s[i] == s[j]) f[i][j] = 1;
    				else f[i][j] = 0;
				}
				else{
					if(f[i+1][j-1] == 1 && s[i] == s[j]) f[i][j] = 1;
    				else f[i][j] = 0;
				}
			}
		}
    
	/*	
		for(int a=0; a<n; a++){
			for(int b=0; b<n; b++){
				cout << f[a][b] << " ";
			}
			cout << endl;
		}
	*/	
		
		int d = 0; 
		int max = 0;
		int max_i = 0;
		int max_j = 0;
		for(int a=0; a<n; a++){
			for(int b=a; b<n; b++){
				if(f[a][b] == 1){
					d = b - a + 1;
					if(d > max){
						max = d;
						max_i = a;
						max_j = b;
					} 
				}
			}
		}
		int len = max_j - max_i + 1;
		string re;
		re.resize(len);
		for(int a=0; a<len; a++){
			re[a] = s[max_i];
			max_i++;
		} 
        return re;
    }
};

int main(){
	string st;
	cin >> st;
	Solution sol;
	cout << sol.longestPalindrome(st) << endl;
	return 0;
}
